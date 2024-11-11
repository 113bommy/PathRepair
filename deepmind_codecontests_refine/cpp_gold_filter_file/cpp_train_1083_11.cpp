#include <bits/stdc++.h>
using namespace std;
int n, m, k, s;
int maxi[13][13];
int l[13][2003], r[13][2003];
bool ok[13][2003];
int modul(int x) {
  if (x < 0) return -x;
  return x;
}
int a[100003];
int main() {
  int i, j;
  scanf("%d %d %d %d", &n, &m, &k, &s);
  for (i = 0; i < 10; i++)
    for (j = 0; j < n; j++) {
      l[i][j] = m + 1;
      r[i][j] = -1;
    }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      int x;
      scanf("%d", &x);
      ok[x][i] = true;
      l[x][i] = min(l[x][i], j);
      r[x][i] = j;
    }
  }
  for (i = 0; i < 10; i++)
    for (j = i; j < 10; j++) {
      for (int x = 0; x < n; x++)
        for (int xx = 0; xx < n; xx++) {
          if (ok[i][x] & ok[j][xx])
            maxi[i][j] =
                max(maxi[i][j], modul(x - xx) + max(modul(r[j][xx] - l[i][x]),
                                                    modul(r[i][x] - l[j][xx])));
        }
      maxi[j][i] = maxi[i][j];
    }
  for (i = 0; i < s; i++) scanf("%d", &a[i]);
  int ans = 0;
  for (i = 0; i < s - 1; i++) ans = max(ans, maxi[a[i]][a[i + 1]]);
  printf("%d\n", ans);
  return 0;
}
