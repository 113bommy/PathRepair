#include <bits/stdc++.h>
int have[1100][1100];
int h[1100];
int vb[110000], va[110000];
int n, m, a, b, ans1, ans2;
int main() {
  memset(have, 0, sizeof(have));
  memset(h, 0, sizeof(h));
  ans1 = ans2 = 0;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &a, &b);
    have[a][b]++;
    h[b]++;
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d %d", &va[i], &vb[i]);
    if (have[va[i]][vb[i]] > 0) {
      ans1++;
      ans2++;
      have[va[i]][vb[i]]--;
      h[vb[i]]--;
      va[i] = vb[i] = 0;
    }
  }
  for (int i = 1; i <= m; i++) {
    if (va[i] == 0) continue;
    if (h[vb[i]] > 0) {
      ans1++;
      h[vb[i]]--;
    }
  }
  printf("%d %d\n", ans1, ans2);
}
