#include <bits/stdc++.h>
int a[3005][3005];
std::pair<int, int> e[3005 * 3005];
int cntE;
std::bitset<3005> vis[3005];
bool CmpE(std::pair<int, int> x, std::pair<int, int> y) {
  return a[x.first][x.second] < a[y.first][y.second];
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (a[i][i]) {
      printf("NOT MAGIC");
      return 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (a[i][j] != a[j][i]) {
        printf("NOT MAGIC");
        return 0;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      e[++cntE] = std::make_pair(i, j);
    }
  }
  std::sort(e + 1, e + cntE + 1, CmpE);
  for (int i = 1, j; i <= cntE;) {
    j = i;
    while (j + 1 <= cntE &&
           a[e[j].first][e[j].second] == a[e[j + 1].first][e[j + 1].second]) {
      j++;
    }
    for (int k = i; k <= j; k++) {
      if ((vis[e[k].first] & vis[e[k].second]).any()) {
        printf("NOT MAGIC");
        return 0;
      }
    }
    for (int k = i; k <= j; k++) {
      vis[e[k].first][e[k].second] = true;
    }
    i = j + 1;
  }
  printf("MAGIC");
  return 0;
}
