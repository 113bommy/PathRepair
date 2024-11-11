#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;
ll n, m;
ll M = 1e9 + 7;

ll f(ll p) {
	ll re;
	for (re = 1; p > 0; re = re * p-- % M);
	return re;
}

ll g(ll p) {return p > 0 ? p : -p;}

int main()
{
	cin >> n >> m;
    cout << f(n) * f(m) * max(0LL, 2 - g(n - m)) % M << endl;
    return 0;
}