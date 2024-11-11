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



int main()
{
	ios::sync_with_stdio(false);

	int n, m, W, w[16], K = 0;
	cin >> n >> m >> W;
	--m;
	int f[12345], top;
	for (int i = 0; i < n; ++i)
	{
		int k;
		cin >> k;
		int s = 0;
		for (int j = 0; j < k; ++j, ++K)
		{
			cin >> w[K];
			s |= 1 << K;
		}
		f[i] = s;
		if (s)
			top = i;
	}
	if (f[0] == (1 << K) - 1)
	{
		cout << 0 << endl;
		return 0;
	}

	int sum_w[1 << 15];
	for (int i = 0; i < 1 << K; ++i)
	{
		int s = 0;
		for (int j = 0; j < K; ++j)
			if (i >> j & 1)
				s += w[j];
		sum_w[i] = s;
	}

	int dp[1 << 15];
	dp[0] = 0;
	for (int S = 1; S < 1 << K; ++S)
	{
		dp[S] = 1 << 27;
		for (int T = S; T > 0; T = --T & S)
		{
			if (sum_w[T] <= W)
				min_swap(dp[S], dp[S ^ T] + 1);
		}
	}

	int rider = 0;
	int res = abs(m - top);
	for (int i = top; i > 0; --i)
	{
		rider |= f[i];
		res += dp[rider] * 2 - 1;
	}
	cout << res << endl;
}