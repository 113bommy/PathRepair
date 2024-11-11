#include <bits/stdc++.h>
using namespace std;
int n, m, k, s, l[9][2000], r[9][2000], d[9][9];
int main() {
  scanf("%d%d%d%d", &n, &m, &k, &s);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 9; j++) {
      l[j][i] = -1;
      r[j][i] = -1;
    }
    for (int j = 0; j < m; j++) {
      int a;
      scanf("%d", &a);
      a--;
      if (l[a][i] == -1) l[a][i] = j;
      r[a][i] = j;
    }
  }
  for (int a1 = 0; a1 < k; a1++)
    for (int a2 = a1; a2 < k; a2++) {
      int dist = 0;
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
          if (l[a1][i] >= 0 && r[a2][j] >= 0)
            dist = max(dist, abs(i - j) + abs(l[a1][i] - r[a2][j]));
          if (r[a1][i] >= 0 && l[a2][j] >= 0)
            dist = max(dist, abs(i - j) + abs(r[a1][i] - l[a2][j]));
        }
      d[a1][a2] = dist;
      d[a2][a1] = dist;
    }
  int ans = 0, s1, s2;
  scanf("%d", &s1);
  for (int i = 1; i < s; i++) {
    scanf("%d", &s2);
    ans = max(ans, d[s1 - 1][s2 - 1]);
    s1 = s2;
  }
  printf("%d\n", ans);
}
