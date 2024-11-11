#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const int N = 2e5 + 2;
const int inf = 2e9;
const long long linf = 4e18;
long long a[N];
int n;
long long t;
long long f(int l, int r) {
  if (l == r) {
    if (a[l] < t)
      return 1;
    else
      return 0;
  }
  int m = (l + r) >> 1;
  long long ans = f(l, m) + f(m + 1, r);
  vector<int> p;
  long long su = 0;
  for (int i = m; i >= l; i--) {
    su += a[i];
    p.push_back(su);
  }
  sort(p.begin(), p.end());
  su = 0;
  for (int i = m + 1; i <= r; i++) {
    su += a[i];
    ans += lower_bound(p.begin(), p.end(), t - su) - p.begin();
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cerr.tie(0);
  cin >> n >> t;
  for (int i = 0; i < n; i++) cin >> a[i];
  cout << f(0, n - 1);
  return 0;
}
