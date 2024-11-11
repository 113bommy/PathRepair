#include <bits/stdc++.h>
using namespace std;
void fre() {
  freopen("c://test//input.in", "r", stdin);
  freopen("c://test//output.out", "w", stdout);
}
template <class T1, class T2>
inline void gmax(T1 &a, T2 b) {
  if (b > a) a = b;
}
template <class T1, class T2>
inline void gmin(T1 &a, T2 b) {
  if (b < a) a = b;
}
const int N = 0, M = 0, Z = 1e9 + 7, ms63 = 0x3f3f3f3f;
int n, m;
int y, x;
int ln[1010], ls[1010];
int main() {
  while (~scanf("%d%d", &n, &m)) {
    memset(ln, 1, sizeof(ln));
    memset(ls, 1, sizeof(ls));
    for (int i = 1; i <= m; ++i) {
      scanf("%d%d", &y, &x);
      ln[y] = 0;
      ls[x] = 0;
    }
    int ans = 0;
    for (int i = 2; i < n; ++i)
      if (ln[i]) ++ans;
    for (int j = 2; j < n; ++j)
      if (ls[j]) {
        int lstep = j - 1;
        int rstep = n - j;
        if (lstep == rstep && ln[lstep]) continue;
        ++ans;
      }
    printf("%d\n", ans);
  }
  return 0;
}
