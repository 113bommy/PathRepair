#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  double ans;
  if (n & 1) {
    ans = cos(0.78539816339744830962 / n) / sin(1.57079632679489661923 / 4);
  } else {
    ans = 1.0 / tan(1.57079632679489661923 / n);
  }
  printf("%.9f\n", ans);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
