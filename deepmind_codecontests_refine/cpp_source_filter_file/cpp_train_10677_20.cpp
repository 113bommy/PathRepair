#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[3005];
pair<int, int> v[3005];
int vs;
int g[3005][3005];
char u[3005][3005];
bool fn[3005];
int main() {
  scanf("%d %d", &n, &m);
  for (int i = (0); i < (m); i++) scanf("%d", a + i);
  int s = 0, p = 6000;
  for (int i = (1); i < (n + 1); i++) {
    int mx = min(i * (i - 1) + (n - i) * i * 2 - s, p);
    if (i <= m) {
      if (a[i - 1] > mx) {
        printf("no\n");
        return 0;
      }
    } else
      a[i - 1] = mx;
    s += a[i - 1];
    p = max(p, a[i - 1]);
  }
  if (s != n * (n - 1)) {
    printf("no\n");
    return 0;
  }
  printf("yes\n");
  for (int i = (0); i < (n); i++) {
    vs = 0;
    for (int j = (0); j < (n); j++)
      if (!fn[j]) v[vs++] = make_pair(-a[j], j);
    sort(v, v + vs);
    p = v[0].second;
    int o = 2 * (n - i - 1) - a[p];
    for (int k = 1; k < vs;) {
      int j;
      for (int z = (0); z < (2); z++)
        for (j = k; j < vs && v[k].first == v[j].first; j++)
          if (o) {
            a[v[j].second]--;
            g[p][v[j].second]++;
            o--;
          } else
            g[v[j].second][p]++;
      k = j;
    }
    fn[p] = true;
  }
  for (int i = (0); i < (n); i++)
    for (int j = (0); j < (n); j++) u[i][j] = i == j ? 'X' : "WDL"[g[i][j]];
  for (int i = (0); i < (n); i++) printf("%s\n", u[i]);
}
