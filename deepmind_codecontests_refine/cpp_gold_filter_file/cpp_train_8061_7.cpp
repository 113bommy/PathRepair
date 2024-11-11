#include <bits/stdc++.h>
using namespace std;
int n, m;
long long int a[100010], b[100010];
long long int f(int x) {
  long long int ans = 0LL;
  for (int i = 0; i < n; i++) {
    ans += max(0LL, x - a[i]);
  }
  for (int i = 0; i < m; i++) {
    ans += max(0LL, b[i] - x);
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  long long int lo = 1, hi = 1e9;
  while (lo + 5 <= hi) {
    long long int m1 = (lo + (hi - lo) / 3);
    long long int m2 = (hi - (hi - lo) / 3);
    long long int r1 = f(m1), r2 = f(m2);
    if (r1 < r2) {
      hi = m2;
    } else if (r1 > r2) {
      lo = m1;
    } else {
      lo = m1, hi = m2;
    }
  }
  long long int ans = 1e18;
  for (long long int i = lo; i <= hi; i++) {
    ans = min(ans, f(i));
  }
  cout << ans << endl;
  return 0;
}
