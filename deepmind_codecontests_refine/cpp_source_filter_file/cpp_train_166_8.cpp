#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5005;
int n, m, cnt;
int u[MAXN], d[MAXN], l[MAXN], r[MAXN];
char c[MAXN];
string mat[MAXN];
bool check(int x, int y) { return (x >= 0 && x < n && y >= 0 && y < m); }
int id(int x, int y) { return check(x, y) ? x * m + y : -1; }
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
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int k = id(i, j);
      u[k] = id(i - 1, j);
      d[k] = id(i + 1, j);
      l[k] = id(i, j - 1);
      r[k] = id(i, j + 1);
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int k = id(i, j);
      if (c[k] == '.') {
        del(k);
      }
    }
  }
}
int gao(int k) {
  if (k == -1) return 0;
  int next = -1;
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
  for (int i = 0; i < n; ++i) {
    cin >> mat[i];
    for (int j = 0; j < m; ++j) {
      c[id(i, j)] = mat[i][j];
    }
  }
  build();
  int ans = 0, cnt = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (mat[i][j] != '.') {
        int tmp = gao(id(i, j));
        if (ans < tmp)
          ans = tmp, cnt = 1;
        else if (ans == tmp)
          ++cnt;
      }
    }
  }
  cout << ans - 1 << " " << cnt << endl;
}
