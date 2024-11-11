#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;
int ccn(int n, int k) {
  int t = n;
  int sm = n / k;
  while (sm > 0) {
    t += sm;
    sm /= k;
  }
  return t;
}
void solve() {
  int n, k;
  scanf("%d%d", &n, &k);
  int t = n / 2;
  int l = 0;
  int r = n;
  int ans = 2e9;
  while (l < r) {
    int mid = (l + r) / 2;
    if (ccn(mid, k) >= n) {
      r = mid;
      ans = min(ans, mid);
    } else {
      l = mid;
    }
    if (l == r || abs(l - r) == 1) break;
  }
  cout << ans << endl;
}
int main() {
  solve();
  return 0;
}
