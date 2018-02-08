// Samantha Scaglione
// Taeho Jung
// Cryptography
// 7 February 2018
//	PA-01: RSA
//	This program will take the following
//	inputs from the command line:
//		$p $q $e $m
//	with a space as their delimiter as shown.
//	Given those inputs, the program will
//	output the values of the following
//	parameters:
//		n = pq
//		d mod φ(n)
//		c = m^e mod n
//


// Pre-Processor Directives
#include <iostream>
#include <gmp.h>
using namespace std;

// Main Function
int main(){

	// Variable Initializations
	mpz_t p, q, e, m, n, d, c, phi, pD, qD;
	mpz_init(p);
	mpz_init(q);
	mpz_init(e);
	mpz_init(m);
	mpz_init(n);
	mpz_init(d);
	mpz_init(c);
	mpz_init(phi);
	mpz_init(pD);
	mpz_init(qD);

	// User Input
	cout << "Input $p $q $e $m with spaces as delimiters:";
	cin >> p;
	cin >> q;
	cin >> e;
	cin >> m;

	// Setup

		// Compute the modulus of the cryptosystem
	mpz_mul(n, p, q);		// perform and store n = pq

		// Output n = pq
	gmp_printf("n = %Zd\n", n);


	// Key Generation

		// Compute n's Euler's totient function
	mpz_sub_ui(pD, p, 1);	// perform and store p - 1
	mpz_sub_ui(qD, q, 1);	// perform and store q - 1
	mpz_mul(phi, pD, qD);	// perform and store phi = (p - 1) (q - 1)

		// Find d, e's multiplicative inverse modulo n
	mpz_invert(d, e, n);

		// Output d mod phi(n)
	gmp_printf("d = %Zd\n", d);

	// Encryption

		// c := m^e mod n
	mpz_powm(c, m, e, n);	// perform and store c = m^e mod n

		// Output c = m^e mod n
	gmp_printf("c = %Zd\n", c);

	// Clear mpz_t Variables
	mpz_clear(p);
	mpz_clear(q);
	mpz_clear(e);
	mpz_clear(m);
	mpz_clear(n);
	mpz_clear(d);
	mpz_clear(c);
	mpz_clear(phi);
	mpz_clear(pD);
	mpz_clear(qD);

	// Return Statement
	return 0;
}
