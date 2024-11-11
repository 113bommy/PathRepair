#include <bits/stdc++.h>
using namespace std;
long long n, m, a[300005];
bool check(long long x) {
  vector<long long> v(a, a + n + 1);
  for (__typeof((n + 1)) i = (1); i < (n + 1); i++) {
    if (v[i] > v[i - 1]) {
      if ((v[i] + x) % m < v[i] && (v[i] + x) % m >= v[i - 1]) v[i] = v[i - 1];
    } else {
      if ((v[i - 1] - v[i]) <= x)
        v[i] = v[i - 1];
      else
        return 0;
    }
  }
  return 1;
}
void solve() {
  cin >> n >> m;
  for (__typeof((n + 1)) i = (1); i < (n + 1); i++) cin >> a[i];
  long long l = 0, r = m - 1, mid;
  while (r - l > 1) {
    mid = (l + r) / 2;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  if (check(l)) {
    cout << l << "\n";
    return;
  };
  {
    cout << r << "\n";
    return;
  };
}
void prep() {}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  prep();
  cout << fixed << setprecision(12);
  while (t--) solve();
  return 0;
}
