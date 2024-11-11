#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 3) + (x << 1) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
const long long inf = 1e18;
int cnt, c[120], f[(1 << 8) + 100];
pair<int, int> q[300];
struct Mat {
  long long a[100][100];
  Mat operator*(const Mat &A) const {
    Mat tmp;
    for (int i = 1; i <= cnt; ++i)
      for (int j = 1; j <= cnt; ++j) tmp.a[i][j] = inf;
    for (int i = 1; i <= cnt; ++i)
      for (int j = 1; j <= cnt; ++j)
        for (int k = 1; k <= cnt; ++k)
          tmp.a[i][j] = min(tmp.a[i][j], a[i][k] + A.a[k][j]);
    return tmp;
  }
  Mat operator^(int p) {
    Mat x, r;
    for (int i = 1; i <= cnt; ++i)
      for (int j = 1; j <= cnt; ++j)
        if (i != j)
          r.a[i][j] = inf;
        else
          r.a[i][i] = 0;
    for (int i = 1; i <= cnt; ++i)
      for (int j = 1; j <= cnt; ++j) x.a[i][j] = a[i][j];
    while (p) {
      if (p & 1) r = x * r;
      x = x * x;
      p >>= 1;
    }
    return r;
  }
};
int main() {
  int x = read(), k = read(), n = read(), Q = read();
  for (int i = 1; i <= k; ++i) c[i] = read();
  for (int i = 1; i <= Q; ++i) q[i].first = read(), q[i].second = read();
  cnt = 0;
  for (int i = 1; i < (1 << k); ++i)
    if (__builtin_popcount(i) == x) f[i] = ++cnt;
  Mat tmp;
  for (int i = 1; i <= cnt; ++i)
    for (int j = 1; j <= cnt; ++j) tmp.a[i][j] = inf;
  for (int i = 1; i < (1 << k); ++i) {
    if (!f[i]) continue;
    if (i & 1)
      for (int j = 1; j <= k; ++j) {
        if ((1 << j) & i) continue;
        tmp.a[f[((1 << j) | i) >> 1]][f[i]] = c[j];
      }
    else
      tmp.a[f[i >> 1]][f[i]] = 0;
  }
  sort(q + 1, q + Q + 1);
  Mat ans;
  for (int i = 1; i <= cnt; ++i)
    for (int j = 1; j <= cnt; ++j) ans.a[i][j] = inf;
  ans.a[1][1] = 0;
  long long sum = 0;
  int now = 1;
  for (int i = 1; i <= Q; ++i) {
    if (q[i].first > n - x) {
      sum += q[i].second;
      continue;
    }
    ans = (tmp ^ (q[i].first - now)) * ans;
    now = q[i].first;
    for (int j = 1; j < (1 << k); j += 2) {
      if (f[j]) ans.a[f[j]][1] += q[i].second;
    }
  }
  ans = (tmp ^ (n - x + 1 - now)) * ans;
  cout << ans.a[1][1] + sum << endl;
  return 0;
}
