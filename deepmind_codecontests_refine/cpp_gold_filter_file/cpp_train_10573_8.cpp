#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 1;
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
void solve() {
  int k2, k3, k5, k6;
  cin >> k2 >> k3 >> k5 >> k6;
  int big = min(k2, min(k5, k6)), ans = 0;
  ans += big * 256;
  k2 -= big;
  if (k2 > 0 and k3 > 0) {
    int small = min(k2, k3);
    ans += small * 32;
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
