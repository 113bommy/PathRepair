#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
int x, k, n, q, cnt;
int c[10], num[270], sta[270], id[270];
pair<int, int> s[30];
struct Mat {
  long long s[72][72];
  friend Mat operator*(const Mat &a, const Mat &b) {
    static Mat c;
    for (int i = 1; i <= cnt; ++i)
      for (int j = 1; j <= cnt; ++j) {
        c.s[i][j] = inf;
        for (int k = 1; k <= cnt; ++k)
          c.s[i][j] = min(c.s[i][j], a.s[i][k] + b.s[k][j]);
      }
    return c;
  }
} f, g, A;
inline Mat qpow(Mat x, int k) {
  static Mat r;
  for (int i = 1; i <= cnt; ++i)
    for (int j = 1; j <= cnt; ++j) r.s[i][j] = inf;
  for (int i = 1; i <= cnt; ++i) r.s[i][i] = 0;
  for (; k; k >>= 1, x = x * x)
    if (k & 1) r = r * x;
  return r;
}
int main() {
  scanf("%d%d%d%d", &x, &k, &n, &q);
  for (int i = 1; i <= k; ++i) scanf("%d", &c[i]);
  for (int i = 1; i <= q; ++i) scanf("%d%d", &s[i].first, &s[i].second);
  sort(s + 1, s + q + 1);
  int ed = 0;
  for (int i = 0; i < x; ++i) ed |= 1 << k - i - 1;
  for (int i = 0; i < 1 << k; ++i) {
    num[i] = num[i >> 1] + (i & 1);
    if (num[i] == x) id[i] = ++cnt, sta[cnt] = i;
  }
  for (int i = 1; i <= cnt; ++i)
    for (int j = 1; j <= cnt; ++j) f.s[i][j] = inf, A.s[i][i] = inf;
  for (int i = 1; i <= cnt; ++i) {
    int state = sta[i], nxt;
    if (state & 1) {
      nxt = (state >> 1) | (1 << k - 1);
      f.s[id[state]][id[nxt]] = c[k];
    } else {
      for (int j = 0; j < k; ++j)
        if (state >> j & 1) {
          nxt = ((state ^ (1 << j)) >> 1) | (1 << k - 1);
          f.s[id[state]][id[nxt]] = c[k - j];
        }
      nxt = state >> 1;
      f.s[id[state]][id[nxt]] = 0;
    }
  }
  int lst = x;
  A.s[1][id[ed]] = 0;
  for (int i = 1; i <= q; ++i) {
    A = A * qpow(f, s[i].first - lst);
    lst = s[i].first;
    for (int j = 1; j <= cnt; ++j)
      if (sta[j] >> k - 1 & 1) A.s[1][j] += s[i].second;
  }
  A = A * qpow(f, n - lst);
  printf("%lld\n", A.s[1][id[ed]]);
  return 0;
}
