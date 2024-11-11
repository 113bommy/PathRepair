#include <iostream>
#include <string>
#include <complex>
#include <cstdlib>
#include <cctype>
using namespace std;

int p;
string str;
bool v;

complex<int> expr();
complex<int> factor();
complex<int> term();

bool isValid(complex<int>& c)
{
	if(abs(c.real()) > 10000 || abs(c.imag()) > 10000) return false;
	return true;
}

complex<int> parseInt()
{
	int res = 0;
	while(isdigit(str[p])) {
		res *= 10;
		res += str[p] - '0';
		p++;

		v &= isValid(complex<int>(res, 0));
	}

	return complex<int>(res, 0);
}

complex<int> expr()
{
	complex<int> l = factor();
	while(str[p] == '+' || str[p] == '-') {
		char op = str[p++];

		complex<int> r = factor();
		if(op == '+') l += r;
		if(op == '-') l -= r;

		v &= isValid(l);
	}

	return l;
}


complex<int> factor()
{
	complex<int> l = term();
	while(str[p] == '*') {
		p++;

		complex<int> r = term();

		l *= r;
		v &= isValid(l);
	}

	return l;
}

complex<int> term()
{
	complex<int> l;
	if(str[p] == '(') {
		p++;
		l = expr();
		p++;
	}
	else if(str[p] == 'i') {
		l = complex<int>(0, 1);
		p++;
	}
	else {
		l = parseInt();
	}

	v &= isValid(l);

	return l;
}



int main()
{
	while(cin >> str) {
		v = true;
		str += '$';
		p = 0;

		complex<int> res = expr();

		if(v == false) cout << "overflow" << endl;
		else {
			if(res.real() == 0 && res.imag() == 0) {
				cout << res.real() << endl;
			}
			else if(res.real() == 0) {
				cout << res.imag() << "i" << endl;
			}
			else if(res.imag() == 0) {
				cout << res.real() << endl;
			}
			else {
				cout << res.real() << (res.imag() > 0 ? "+" : "-") << abs(res.imag()) << "i" << endl;
			}
		}
	}
}