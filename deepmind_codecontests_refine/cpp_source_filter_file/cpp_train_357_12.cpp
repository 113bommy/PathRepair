#include <bits/stdc++.h>
long long mpow(long long a, long long n, long long mod) {
  long long ret = 1;
  long long b = a;
  while (n) {
    if (n & 1) ret = (ret * b) % mod;
    b = (b * b) % mod;
    n >>= 1;
  }
  return (long long)ret;
}
using namespace std;
bool chk(int x, int y, int z, int X, int Y, int Z) {
  if (y <= Z) {
    return 0;
  }
  while (x > 0 && X > 0) {
    x -= max(0, Y - z);
    X -= max(0, y - Z);
  }
  if (x > 0) return 1;
  return 0;
}
void solve() {
  int hy, ay, dy, hm, am, dm, ch, ca, cm;
  scanf("%d", &hy);
  scanf("%d", &ay);
  scanf("%d", &dy);
  scanf("%d", &hm);
  scanf("%d", &am);
  scanf("%d", &dm);
  scanf("%d", &ch);
  scanf("%d", &ca);
  scanf("%d", &cm);
  int ans = 1e9;
  for (int i = 0; i <= 501; i++) {
    for (int j = 0; j <= 501; j++) {
      int lo = 0, hi = 501;
      while (lo < hi) {
        int mid = (lo + hi) >> 1;
        if (chk(i + hy, j + ay, mid + dy, hm, am, dm)) {
          hi = mid;
        } else {
          lo = mid + 1;
        }
      }
      if (chk(hy + i, j + ay, lo + dy, hm, am, dm))
        ans = min(ans, i * ch + j * ca + lo * cm);
    }
  }
  printf("%d", ans);
}
int main() {
  int t = 1;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
