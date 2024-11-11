#include <cstdio>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
using namespace std;
typedef std::pair<ll, ll> mp;
#define fi first
#define se second
#define MOD 1000000007
inline ll read()
{
	ll x = 0, f = 1; char ch = getchar();
	while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
	while (isdigit(ch)) { (x *= 10) += ch - '0'; ch = getchar(); }
	return x * f;
}

const int maxk = 100, mod = 1000000007;
ll fib[maxk], res; int mx;
std::vector<mp> excellent[maxk];

int main() {
	int k = 1;
	fib[0] = fib[1] = 1;
	ll lim = 1000000000000000000;
	while(fib[k] + fib[k - 1] <= lim) {
		++ k;
		fib[k] = fib[k - 1] + fib[k - 2];
	}

 excellent[1].push_back(mp(1, 2));
	for (int i = 2; i <= k; i++)
	{
		for (pair<ll, ll> p : excellent[i-1])
			excellent[i].push_back(mp(p.se, p.fi + p.se));
		excellent[i].push_back(mp(fib[i+1], fib[i+1] + fib[i-1]));
	}

 int T = read();
	while (T--)
	{
		ll x = read(), y = read(); mx = 1, res = 0;
		if (x > y) swap(x, y);
		while (mx+2 <= k && fib[mx+1] <= x && fib[mx+2] <= y) mx++;
		for (pair<ll, ll> p : excellent[mx])
		{
			if (p.fi <= x && p.se <= y)
				(res += (y - p.se) / p.fi + 1) %= MOD;
			if (p.se <= x)
				(res += (x - p.se) / p.fi + 1) %= MOD;
		}
		if (mx == 1) res += x;
		printf("%d %lld\n", mx, res);
	}
}