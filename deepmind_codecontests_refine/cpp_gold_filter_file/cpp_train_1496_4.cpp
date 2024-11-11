#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[10005][105], b[10005];
inline int swaprow(int x, int y) {
  int t;
  for (int i = 0; i < n; i++) {
    t = a[x][i];
    a[x][i] = a[y][i];
    a[y][i] = t;
  }
  t = b[x];
  b[x] = b[y];
  b[y] = t;
  return 0;
}
inline int addrow(int x, int y) {
  for (int i = 0; i < n; i++) {
    a[y][i] += a[x][i];
    while (a[y][i] < 0) a[y][i] += 2;
    while (a[y][i] >= 2) a[y][i] -= 2;
  }
  b[y] += b[x];
  while (b[y] < 0) b[y] += 2;
  while (b[y] >= 2) b[y] -= 2;
  return 0;
}
inline int print() {
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) printf("%d ", a[i][j]);
    printf("| %d\n", b[i]);
  }
  printf("\n");
  return 0;
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++) a[i][j] = 0;
  int u, v, w;
  for (int i = 0; i < m; i++) {
    scanf("%d %d %d", &u, &v, &w);
    u--;
    v--;
    a[i][u] = 1;
    a[i][v] = 1;
    if (w)
      b[i] = 0;
    else
      b[i] = 1;
  }
  int c = 0, r = 0;
  while (c < n && r < m) {
    int p = r;
    while (p < m && a[p][c] == 0) p++;
    if (p >= m) {
      c++;
      continue;
    }
    swaprow(r, p);
    for (int i = r + 1; i < m; i++) {
      if (a[i][c]) addrow(r, i);
    }
    r++;
    c++;
  }
  for (int i = r; i < m; i++) {
    if (b[i] != 0) {
      printf("Impossible\n");
      return 0;
    }
  }
  vector<int> sol;
  for (int i = r - 1; i >= 0; i--) {
    for (int j = n - 1; j >= 0; j--) {
      if (a[i][j] == 1) {
        if (b[i]) {
          sol.push_back(j);
          b[i] = 0;
          for (int k = i - 1; k >= 0; k--) {
            if (a[k][j] == 1) {
              a[k][j] = 0;
              if (b[k])
                b[k] = 0;
              else
                b[k] = 1;
            }
          }
        } else {
          for (int k = i - 1; k >= 0; k--) {
            if (a[k][j] == 1) {
              a[k][j] = 0;
            }
          }
        }
      }
    }
    if (b[i]) {
      printf("Impossible\n");
      return 0;
    }
  }
  printf("%d\n", n - sol.size());
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < sol.size(); j++) {
      if (sol[j] == i)
        break;
      else if (j == sol.size() - 1)
        printf("%d ", i + 1);
    }
  }
  return 0;
}
