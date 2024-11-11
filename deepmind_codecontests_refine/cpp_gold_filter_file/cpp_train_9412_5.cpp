#include <bits/stdc++.h>
using namespace std;
const int NS = 100010;
const int MS = (1 << 20) + 10;
int n, m, d;
int bel[NS];
int ok[MS], one[MS];
int num[21];
int main() {
  while (~scanf("%d%d%d", &n, &m, &d)) {
    for (int i = 0; i < m; i++) {
      int x, y;
      scanf("%d", &y);
      for (int j = 0; j < y; j++) {
        scanf("%d", &x);
        bel[x] = i;
      }
    }
    int lim = 1 << m;
    for (int i = 0; i <= m; i++) num[i] = 0;
    for (int i = 0; i < lim; i++) ok[i] = true;
    for (int i = 0; i <= n; i++) {
      num[bel[i]]++;
      if (i >= d) {
        num[bel[i - d]]--;
        int mask = 0;
        for (int j = 0; j < m; j++)
          if (num[j]) mask |= (1 << j);
        ok[mask] = false;
      }
    }
    one[0] = 0;
    for (int i = 1; i < lim; i++) {
      one[i] = one[i >> 1] + (i & 1);
      if (!ok[i]) {
        for (int j = 0; j < m; j++) ok[i | (1 << j)] = false;
      }
    }
    int ans = 0;
    for (int i = 0; i < lim; i++)
      if (ok[i]) {
        ans = max(ans, one[i]);
      }
    ans = m - ans;
    printf("%d\n", ans);
  }
  return 0;
}
