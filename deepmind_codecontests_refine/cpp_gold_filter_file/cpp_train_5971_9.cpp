#include <bits/stdc++.h>
using namespace std;
bool G(long long m, int k, long long n) {
  long long ts = 1;
  n--;
  m = m * k;
  for (int j = 1; j <= k && n > 0; j++) {
    ts = ts * (k - j + 1) / j;
    if (ts * j <= m) {
      m -= ts * j;
      n -= ts;
    } else {
      n -= m / j;
      break;
    }
  }
  return (n <= 0);
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m;
    scanf("%d%d", &n, &m);
    int l = -1, r = n;
    while (l + 1 < r) {
      int mid = l + r >> 1;
      if (G(m, mid, n))
        r = mid;
      else
        l = mid;
    }
    printf("%d\n", r);
  }
  return 0;
}
