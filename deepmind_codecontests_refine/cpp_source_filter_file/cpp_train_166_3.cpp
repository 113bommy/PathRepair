#include <bits/stdc++.h>
using namespace std;
int n, m, cnt;
int u[10005], d[10005], l[10005], r[10005];
char c[10005];
string mat[5005];
int id(int x, int y) { return x * (m + 2) + y; }
void add(int k) {
  u[d[k]] = k;
  d[u[k]] = k;
  l[r[k]] = k;
  r[l[k]] = k;
}
void del(int k) {
  u[d[k]] = u[k];
  d[u[k]] = d[k];
  l[r[k]] = l[k];
  r[l[k]] = r[k];
}
void build() {
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      int k = id(i, j);
      u[k] = id(i - 1, j);
      d[k] = id(i + 1, j);
      l[k] = id(i, j - 1);
      r[k] = id(i, j + 1);
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (mat[i][j - 1] == '.') {
        del(id(i, j));
      }
    }
  }
}
int gao(int k) {
  if (!k) return 0;
  int next = 0;
  if (c[k] == 'U') next = u[k];
  if (c[k] == 'D') next = d[k];
  if (c[k] == 'L') next = l[k];
  if (c[k] == 'R') next = r[k];
  del(k);
  int mov = gao(next) + 1;
  add(k);
  return mov;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> mat[i];
    for (int j = 0; j < m; ++j) {
      c[id(i, j + 1)] = mat[i][j];
    }
  }
  build();
  int ans = 0, cnt = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (mat[i][j - 1] != '.') {
        int tmp = gao(id(i, j));
        if (ans < tmp)
          ans = tmp, cnt = 1;
        else if (ans == tmp)
          ++cnt;
      }
    }
  }
  cout << ans << " " << cnt << endl;
}
