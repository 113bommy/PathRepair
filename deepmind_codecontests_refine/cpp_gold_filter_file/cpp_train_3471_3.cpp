#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int MAX = 2e5 + 5;
const long long MAX2 = 11;
const long long MOD = 1000000007;
const long long MOD2 = 1000005329;
const long long INF = 2e18;
const int dr[] = {1, 0, -1, 0, 1, 1, -1, -1, 0};
const int dc[] = {0, 1, 0, -1, 1, -1, 1, -1, 0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;
long long n, k, y[MAX], z, le, ri, mid, ans, rem, bt, opt[MAX];
pair<long long, long long> x[MAX];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k >> z;
  --n;
  for (int i = 1; i <= n; ++i)
    cin >> x[i].first, y[i] = x[i].first, x[i].second = i;
  sort(x + 1, x + 1 + n);
  opt[n + 1] = n + 1;
  for (int i = n; i >= 1; --i) opt[i] = min(x[i].second, opt[i + 1]);
  reverse(x + 1, x + 1 + n);
  ans = n + 1;
  le = 1, ri = n;
  while (le <= ri) {
    mid = le + ri >> 1;
    rem = z;
    bt = k - 1;
    for (int i = 1; i <= bt; ++i) {
      if (x[i].second == opt[mid])
        ++bt;
      else
        rem -= x[i].first;
    }
    if (rem - y[opt[mid]] < 0)
      ans = opt[mid], ri = mid - 1;
    else
      le = mid + 1;
  }
  cout << ans << '\n';
  return 0;
}
