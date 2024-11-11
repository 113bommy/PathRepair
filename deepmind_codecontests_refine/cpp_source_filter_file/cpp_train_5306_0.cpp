#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>


using namespace std;

#ifdef _MSC_VER
#define __typeof__ decltype
template <class T> int __builtin_popcount(T n) { return n ? 1 + __builtin_popcount(n & (n - 1)) : 0; }
#endif

#define foreach(it, c) for (__typeof__((c).begin()) it=(c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define CLEAR(arr, val) memset(arr, val, sizeof(arr))

#define rep(i, n) for (int i = 0; i < n; ++i)

template <class T> void max_swap(T& a, const T& b) { a = max(a, b); }
template <class T> void min_swap(T& a, const T& b) { a = min(a, b); }

typedef long long ll;
typedef pair<int, int> pint;

const double EPS = 1e-8;
const double PI = acos(-1.0);
const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { 1, 0, -1, 0 };
bool valid_pos(int x, int y, int w, int h) { return 0 <= x && x < w && 0 <= y && y < h; }


ll mod_mul(ll x, ll n, ll mod)
{
	if (n == 0)
		return 0;
	if (x < 0)
		x = (x + mod) % mod;
	if (y < 0)
		y = (y + mod) % mod;
	//bool nega = n < 0;
	//if (nega)
	//	n = -n;

	ll res = 0;
	while (n > 0)
	{
		if (n & 1)
			res = (res + x) % mod;
		x = x * 2 % mod;
		n /= 2;
	}

	//if (nega)
	//	res = (mod - res) % mod;
	return res;
}
ll ext_gcd(ll a, ll b, ll &x, ll &y)
{
	if (b)
	{
		ll g = ext_gcd(b, a % b, y, x);
		y -= (a / b) * x;
		return g;
	}
	else
	{
		x = 1, y = 0;
		return a;
	}
}
ll mod_inverse(ll a, ll mod)
{
	ll x, y;
	if (ext_gcd((a + mod) % mod, mod, x, y) == 1)
		return (mod + x % mod) % mod;
	else
		return 0;
}
int main()
{
	ios::sync_with_stdio(false);

	const ll mod = 9999999967LL;

	int n;
	cin >> n;
	ll x = 0;
	while (n--)
	{
		int o, y;
		cin >> o >> y;
		if (o == 1)
			x += y;
		else if (o == 2)
			x -= y;
		else if (o == 3)
			x = mod_mul(x, (y + mod)%mod, mod);
		else
			x = mod_mul(x, mod_inverse(y, mod), mod);

		x = (x + mod) % mod;
	}
	if (x >= 1LL << 31)
		x -= mod;
	cout << x << endl;
}