#include <bits/stdc++.h>
using namespace std;
int read() {
  char ch;
  int sig = 1;
  for (ch = getchar(); ch < '0' || ch > '9'; ch = getchar())
    if (ch == '-') sig = -1;
  int x = ch - '0';
  for (ch = getchar(); ch >= '0' && ch <= '9'; ch = getchar())
    x = x * 10 + ch - '0';
  return x * sig;
}
const int N = 205;
const double eps = 1e-8;
int n;
struct P {
  int x, y;
  P(int _x = 0, int _y = 0) {
    x = _x;
    y = _y;
  }
  friend P operator+(P a, P b) { return P(a.x + b.x, a.y + b.y); }
  friend P operator-(P a, P b) { return P(a.x - b.x, a.y - b.y); }
  friend P operator*(P a, int b) { return P(a.x * b, a.y * b); }
} p[N];
int cross(P a, P b) { return a.x * b.y - a.y * b.x; }
struct Matrix {
  double a[N][N];
  friend Matrix operator*(Matrix a, Matrix b) {
    Matrix c;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) c.a[i][j] = 0;
    for (int k = 1; k <= n; k++)
      for (int i = 1; i <= n; i++)
        if (a.a[i][k] > eps)
          for (int j = 1; j <= n; j++) c.a[i][j] += a.a[i][k] * b.a[k][j];
    return c;
  }
} trs[14], an;
vector<int> q[N * N];
int cnt[N], tot;
bool vis[N][N];
void prepare() {
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
      if (!vis[i][j]) {
        ++tot;
        q[tot].push_back(i);
        q[tot].push_back(j);
        for (int k = j + 1; k <= n; k++)
          if (!cross(p[k] - p[i], p[j] - p[i])) q[tot].push_back(k);
        for (int x = 0; x < q[tot].size(); x++)
          for (int y = x + 1; y < q[tot].size(); y++)
            vis[q[tot][x]][q[tot][y]] = 1;
      }
  for (int i = 1; i <= tot; i++)
    for (int j = 0; j < q[i].size(); j++) cnt[q[i][j]]++;
  for (int i = 1; i <= tot; i++) {
    for (int j = 0; j < q[i].size(); j++)
      for (int k = 0; k < q[i].size(); k++) {
        int x = q[i][j], y = q[i][k];
        trs[0].a[x][y] += 1.0 / q[i].size() / cnt[x];
      }
  }
  for (int i = 1; i <= 13; i++) trs[i] = trs[i - 1] * trs[i - 1];
}
double e[N], now[N];
double solve(int x, int t) {
  for (int i = 1; i <= n; i++) e[i] = i == x;
  for (int k = 0; k <= 13; k++)
    if (t & (1 << k)) {
      for (int i = 1; i <= n; i++) now[i] = 0;
      for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) now[i] += trs[k].a[i][j] * e[j];
      for (int i = 1; i <= n; i++) e[i] = now[i];
    }
  double res = 0;
  for (int i = 1; i <= tot; i++) {
    double sum = 0;
    for (int j = 0; j < q[i].size(); j++) {
      int y = q[i][j];
      sum += e[y] / q[i].size();
    }
    res = max(res, sum);
  }
  return res;
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) p[i].x = read(), p[i].y = read();
  prepare();
  for (int m = read(); m; m--) {
    int x = read(), t = read();
    printf("%.10lf\n", solve(x, t - 1));
  }
  return 0;
}
