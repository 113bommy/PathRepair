#include <bits/stdc++.h>
using namespace std;
inline void read(int& s) {
  s = 0;
  static char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9')
    s = (s << 3) + (s << 1) + (c ^ 48), c = getchar();
  return;
}
const int N = 1000003;
int n, m, a[31], b[31], ans;
int main() {
  read(n), read(m);
  int i, x;
  for (i = 1; i <= n; ++i) {
    read(x);
    int now = 0;
    while (x) {
      if (x & 1) ++a[now];
      ++now, x >>= 1;
    }
  }
  for (i = 1; i <= m; ++i) {
    read(x);
    ++b[x];
  }
  for (i = 0; i < 31; ++i) {
    while (a[i] < b[i]) {
      int f = 1;
      for (register int j = i + 1; j < 31; ++j) {
        if (!a[i]) continue;
        for (register int k = i + 1; k < j; ++k) ++a[i];
        --a[j], a[i] += 2;
        f = 0;
        break;
      }
      if (f) break;
    }
    ans += min(a[i], b[i]);
  }
  printf("%d\n", ans);
  return 0;
}
