#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:10000000")
using namespace std;
const int c = 512;
int n, m;
int x[c], y[c], d[c];
bool a[c][c];
bool b[c];
int p[c];
int dist(int i, int j) { return max(abs(x[i] - x[j]), abs(y[i] - y[j])); }
bool go1(int i) {
  b[i] = 1;
  int j;
  bool q = 0;
  for (j = 1; j <= n; j += 2)
    if (a[i][j]) {
      if (p[j] == -1)
        q = 1;
      else if (!b[p[j]])
        q = go1(p[j]);
      if (q) {
        p[j] = i;
        break;
      }
    }
  return q;
}
bool go2(int i) {
  b[i] = 1;
  int j;
  bool q = 0;
  for (j = 2; j <= n; j += 2)
    if (a[i][j]) {
      if (p[j] == -1)
        q = 1;
      else if (!b[p[j]])
        q = go2(p[j]);
      if (q) {
        p[j] = i;
        break;
      }
    }
  return q;
}
int main() {
  scanf("%d%d", &n, &m);
  int i, j;
  for (i = 1; i <= n; ++i) scanf("%d%d", &x[i], &y[i]);
  for (i = 1; i <= m; ++i) scanf("%d", &d[i]);
  memset(a, 0, sizeof(a));
  for (i = 1; i <= m; ++i)
    for (j = 1; j <= n; j += 2)
      if (dist(j, j % n + 1) + dist(j, (j + n - 2) % n + 1) == d[i])
        a[i][j] = 1;
  int r = 0;
  memset(p, -1, sizeof(p));
  for (i = 1; i <= m; ++i) {
    memset(b, 0, sizeof(b));
    if (go1(i)) ++r;
  }
  if (r == n / 2) {
    printf("YES\n");
    for (i = 1; i <= n; ++i) printf("%d ", p[i]);
  } else {
    memset(a, 0, sizeof(a));
    for (i = 1; i <= m; ++i)
      for (j = 2; j <= n; j += 2)
        if (dist(j, j % n + 1) + dist(j, (j + n - 2) % n + 1) == d[i])
          a[i][j] = 1;
    r = 0;
    memset(p, -1, sizeof(p));
    for (i = 1; i <= m; ++i) {
      memset(b, 0, sizeof(b));
      if (go2(i)) ++r;
    }
    if (r == n / 2) {
      printf("YES\n");
      for (i = 1; i <= n; ++i) printf("%d ", p[i]);
    } else
      printf("NO");
  }
  return 0;
}
