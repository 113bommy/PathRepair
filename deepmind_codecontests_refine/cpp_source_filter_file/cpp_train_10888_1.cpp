#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 7;
const int MOD = 1e9 + 7;
int n;
int h[MAXN];
int main() {
  int m, k, ta, tb;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= m; i++) {
    scanf("%d", &ta);
    h[ta] = 1;
  }
  int cur = 1;
  if (!h[ta])
    for (int i = 0; i < k; i++) {
      scanf("%d%d", &ta, &tb);
      if (ta != cur && tb != cur) continue;
      if (ta == cur && tb == cur) continue;
      if (ta != cur) swap(ta, tb);
      if (h[tb]) {
        printf("%d\n", tb);
        return 0;
      } else {
        cur = tb;
      }
    }
  printf("%d\n", cur);
  return 0;
}
