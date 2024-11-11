#include <bits/stdc++.h>
using namespace std;
const long long INF = (long long)1e18;
const int inf = (int)1e9;
const int N = (int)1e5 + 10;
const int MOD = (int)1e9 + 7;
const int base = 998244353;
const double eps = (double)1e-9;
const double PI = acos(-1.0);
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
int n, k, mn = inf, mx = -inf - 100;
int a[N], mn1[N], mn2[N];
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    mn = min(mn, a[i]);
    mx = max(mx, a[i]);
  }
  if (k == 1)
    cout << mn;
  else if (k == 2) {
    cout << min(a[1], a[n]);
  } else
    cout << mx;
}
