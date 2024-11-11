#include <iostream>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

string toOct(long long  d)
{
	char c[30];
	string s = "";
	
	sprintf(c, "%o", d);
	s += c;

	return s;
}


string solve(long long  n)
{
	char c[30];
	string s;

	s = toOct(n);

	for( int i = 0; i < (int)s.length(); i++)
	{
		if( s[i] >= '4' )
			s[i] += '1' - '0';

		if( s[i] >= '6' )
			s[i] += '1' - '0';
	}

	return s;
}


int main()
{
	long long n;

	while( cin >> n, n)
	{
		cout << solve(n) << endl;
	}

	return 0;
}