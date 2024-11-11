#include <bits/stdc++.h>
using namespace std;
int n, m;
int cnta[10], cntb[10];
int a[15][2], b[15][2];
int one_common(int x, int y) {
  if (a[x][0] == b[y][0] && a[x][1] != b[y][1]) return a[x][0];
  if (a[x][1] == b[y][0] && a[x][0] != b[y][1]) return a[x][1];
  if (a[x][0] == b[y][1] && a[x][1] != b[y][0]) return a[x][0];
  if (a[x][1] == b[y][1] && a[x][0] != b[y][0]) return a[x][1];
  return 0;
}
int main() {
  scanf("%d%d", &n, &m);
  int x, y;
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &x, &y);
    cnta[x]++;
    cnta[y]++;
    a[i][0] = x;
    a[i][1] = y;
  }
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &x, &y);
    cntb[x]++;
    cntb[y]++;
    b[i][0] = x;
    b[i][1] = y;
  }
  set<int> num;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (one_common(i, j)) num.insert(one_common(i, j));
    }
  }
  if (num.size() == 1) {
    printf("%d\n", *num.begin());
    return 0;
  }
  for (int i = 0; i < n; i++) {
    set<int> num;
    for (int j = 0; j < m; j++)
      if (one_common(i, j)) num.insert(one_common(i, j));
    if (num.size() > 1) {
      printf("-1\n");
      return 0;
    }
  }
  for (int i = 0; i < m; i++) {
    set<int> num;
    for (int j = 0; j < n; j++)
      if (one_common(j, i)) num.insert(one_common(i, j));
    if (num.size() > 1) {
      printf("-1\n");
      return 0;
    }
  }
  printf("0\n");
  return 0;
}
