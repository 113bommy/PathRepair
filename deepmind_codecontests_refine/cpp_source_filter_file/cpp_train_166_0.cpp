#include <bits/stdc++.h>
using namespace std;
int n, m, cur, id[5010][5010], l[5010], r[5010], u[5010], d[5010], L[5010],
    R[5010], U[5010], D[5010], a1, a2;
char c[5010][5010], dir[5010];
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> c[i][j];
      if (c[i][j] != '.') {
        id[i][j] = ++cur;
        dir[cur] = c[i][j];
      }
    }
  for (int i = 0; i < n; i++) {
    int pre = 0;
    for (int j = 0; j < m; j++)
      if (c[i][j] != '.') L[id[i][j]] = pre, R[pre] = id[i][j], pre = id[i][j];
  }
  for (int j = 0; j < m; j++) {
    int pre = 0;
    for (int i = 0; i < n; i++)
      if (c[i][j] != '.') U[id[i][j]] = pre, D[pre] = id[i][j], pre = id[i][j];
  }
  for (int i = 1; i < cur + 1; i++) {
    for (int j = 0; j < cur; j++)
      l[j] = L[j], r[j] = R[j], u[j] = U[j], d[j] = D[j];
    int p = 0, now = i;
    while (now) {
      p++;
      l[r[now]] = l[now];
      r[l[now]] = r[now];
      u[d[now]] = u[now];
      d[u[now]] = d[now];
      if (dir[now] == 'L')
        now = l[now];
      else if (dir[now] == 'R')
        now = r[now];
      else if (dir[now] == 'U')
        now = u[now];
      else
        now = d[now];
    }
    if (p > a1)
      a1 = p, a2 = 1;
    else if (p == a1)
      a2++;
  }
  cout << a1 << " " << a2;
}
