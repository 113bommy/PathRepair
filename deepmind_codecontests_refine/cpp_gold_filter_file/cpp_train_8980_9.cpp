#include <bits/stdc++.h>
using namespace std;
const int debug_ = 0;
const int inf_ = 1e9 + 7;
const int offset_ = 220;
long long c[2100][2100];
long long w[2100];
int n, m, r;
long long cal(int x, int y, int xx, int yy, int xy) {
  return w[x] * w[y] * 2 % inf_ *
         (c[n][m] + c[n - xx - yy + xy][m] + inf_ - c[n - xx][m] + inf_ -
          c[n - yy][m]) %
         inf_;
}
int cc[1100][1100];
int ask(int x, int y) {
  int u1 = max(0, x - r - 1), u2 = min(1000, x + r);
  int v1 = max(0, y - r - 1), v2 = min(1000, y + r);
  return cc[u2][v2] - cc[u1][v2] - cc[u2][v1] + cc[u1][v1];
}
int ask(int x, int y, int u, int v) {
  int u1 = max(max(u - r - 1, x - r - 1), 0);
  int u2 = min(min(u + r, x + r), 1000);
  int v1 = max(max(v - r - 1, y - r - 1), 0);
  int v2 = min(min(v + r, y + r), 1000);
  if (u2 <= u1 || v2 <= v1) {
    return 0;
  }
  return cc[u2][v2] - cc[u1][v2] - cc[u2][v1] + cc[u1][v1];
}
int x[2100], y[2100];
int main() {
  c[0][0] = 1;
  for (int i = 1; i <= 2000; ++i) {
    c[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % inf_;
    }
  }
  cin >> n >> m >> r;
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i] >> w[i];
    cc[x[i]][y[i]]++;
  }
  for (int i = 1; i <= 1000; ++i) {
    for (int j = 1; j <= 1000; ++j) {
      cc[i][j] += cc[i][j - 1];
    }
  }
  for (int j = 1; j <= 1000; ++j) {
    for (int i = 1; i <= 1000; ++i) {
      cc[i][j] += cc[i - 1][j];
    }
  }
  long long ret = 0;
  for (int i = 0; i < n; ++i) {
    int xx = ask(x[i], y[i]);
    ret += w[i] * w[i] % inf_ * (c[n][m] + inf_ - c[n - xx][m]) % inf_;
    for (int j = i + 1; j < n; ++j) {
      ret += cal(i, j, xx, ask(x[j], y[j]), ask(x[i], y[i], x[j], y[j]));
    }
  }
  cout << ret % inf_ << endl;
  return 0;
}
