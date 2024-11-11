#include <bits/stdc++.h>
using namespace std;
stack<long int> st1;
long int a[3002][3002], b[4000], c[4000], d[4000], e[4000], f, g, h, k, l, m, n,
    x, y, z, cl, cy, cx;
bool finish = false;
void dfs(long cur, long last, long len) {
  long i;
  for (i = 1; i <= n; i++) {
    if (finish) return;
    if (a[i][cur] == 1 && d[i] == 0) {
      c[len] = i;
      d[i] = 1;
      dfs(i, cur, len + 1);
    } else if (a[i][cur] == 1 && d[i] == 1 && i != last) {
      finish = true;
      c[len] = i;
      cl = len + 1;
      break;
    }
  }
}
void dfss(long cur, long last, long len) {
  long i;
  for (i = 1; i <= n; i++) {
    if (d[i] == 0 && c[i] == 0 && a[cur][i] == 1) {
      c[i] = 1;
      e[i] = len + 1;
      dfss(i, cur, len + 1);
    }
  }
}
int main() {
  scanf("%d", &n);
  long i;
  for (i = 0; i < n; i++) {
    scanf("%d%d", &x, &y);
    a[x][y] = 1;
    a[y][x] = 1;
  }
  d[1] = 1;
  c[0] = 1;
  dfs(1, -1, 1);
  for (i = 0; i <= n; i++) {
    d[i] = 0;
    b[i] = 0;
  }
  i = cl - 2;
  l = 0;
  while (c[i] != c[cl - 1]) {
    b[l] = c[i];
    d[b[l]] = 1;
    l++;
    i--;
  }
  b[l] = c[i];
  d[b[l]] = 1;
  l++;
  for (i = 0; i <= n; i++) {
    c[i] = 0;
  }
  for (i = 0; i < l; i++) {
    for (long j = 0; j <= n; j++) {
      c[j] = 0;
    }
    c[b[i]] = 1;
    dfss(b[i], -1, 0);
  }
  for (i = 0; i < l; i++) {
    e[b[i]] = 0;
  }
  for (i = 1; i <= n; i++) {
    cout << e[i] << " ";
  }
  return 0;
}
