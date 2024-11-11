#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void umax(T &x, T y) {
  if (y > x) x = y;
}
template <class T>
inline void umin(T &x, T y) {
  if (y < x) x = y;
}
const int N = 2e5 + 5, B = 0x7fffffff;
pair<int, int> ro[N], col[N];
int n, m, k, tim;
int main() {
  scanf("%d%d%d", &n, &m, &k);
  while (k--) {
    ++tim;
    int ty, rc, a;
    scanf("%d%d%d", &ty, &rc, &a);
    if (ty == 1)
      ro[rc] = {a, tim};
    else
      col[rc] = {a, tim};
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (ro[i].second > col[j].second)
        printf("%d ", ro[i].first);
      else
        printf("%d ", col[j].first);
    }
    puts("");
  }
  return !1;
}
