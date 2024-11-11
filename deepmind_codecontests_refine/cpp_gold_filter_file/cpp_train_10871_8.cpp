#include <bits/stdc++.h>
using namespace std;
const int K = 1010;
const int N = 1000010;
const int P = 100;
const int B = 11;
const int M = 1000000000;
int n, a[N];
int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  sort(a + 1, a + n + 1);
  int ans = 1 << 30, fst = 0, rto = 0;
  for (int r = 0; r <= 20000; ++r) {
    int lw = 1 << 30, up = -1 << 30, pl = 0;
    for (int i = 1; i <= n; ++i) {
      lw = min(lw, a[1] + (i - 1) * r - a[i]);
      up = max(up, a[1] + (i - 1) * r - a[i]);
      if (up == (i - 1) * r - a[i]) pl = i;
    }
    int now = (up - lw + 1) / 2;
    if (now < ans) {
      ans = now;
      fst = a[1] - lw - now;
      rto = r;
    }
  }
  cout << ans << '\n' << fst << ' ' << rto << '\n';
}
