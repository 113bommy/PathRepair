#include <bits/stdc++.h>
using namespace std;
const int INF = 2147483647;
const long long LLINF = 9223372036854775807LL;
const int maxn = 100010;
const int mod = 1000000007;
int psum[7][maxn];
int t[7][maxn * 4];
bool needset[7][maxn * 4];
int tset[7][maxn * 4];
int a[maxn];
inline int calcsum(int ti, int fr, int to) {
  int result = psum[ti][to];
  if (fr) result = (result + mod - psum[ti][fr - 1]) % mod;
  return result;
}
inline void push(int ti, int v, int L, int R) {
  if (needset[ti][v]) {
    int ls = v + v + 1;
    int rs = v + v + 2;
    needset[ti][v] = false;
    if (L != R) {
      needset[ti][ls] = needset[ti][rs] = true;
      tset[ti][ls] = tset[ti][rs] = tset[ti][v];
    }
    t[ti][v] = tset[ti][v] * (long long)calcsum(ti, L, R) % mod;
  }
}
inline void recalc(int ti, int v, int L, int R) {
  int ls = v + v + 1;
  int rs = v + v + 2;
  int m = (L + R) >> 1;
  push(ti, ls, L, m);
  push(ti, rs, m + 1, R);
  t[ti][v] = (t[ti][ls] + t[ti][rs]) % mod;
}
void build(int ti, int v, int L, int R) {
  if (L == R) {
    t[ti][v] = a[L];
    for (int i = 0; i < ti; ++i) t[ti][v] = (long long)L * t[ti][v] % mod;
  } else {
    int m = (L + R) >> 1;
    build(ti, v + v + 1, L, m);
    build(ti, v + v + 2, m + 1, R);
    recalc(ti, v, L, R);
  }
}
void modify(int ti, int v, int l, int r, int val, int L, int R) {
  push(ti, v, L, R);
  if (L > r || l > R) return;
  if (L >= l && R <= r)
    needset[ti][v] = true, tset[ti][v] = val;
  else {
    int m = (L + R) >> 1;
    push(ti, v, L, R);
    modify(ti, v + v + 1, l, r, val, L, m);
    modify(ti, v + v + 2, l, r, val, m + 1, R);
    recalc(ti, v, L, R);
  }
}
int comb[7][7];
int query(int ti, int v, int l, int r, int L, int R) {
  push(ti, v, L, R);
  if (l > R || L > r) return 0;
  if (l <= L && r >= R)
    return t[ti][v];
  else {
    int m = (L + R) >> 1;
    int q1 = query(ti, v + v + 1, l, r, L, m);
    int q2 = query(ti, v + v + 2, l, r, m + 1, R);
    return (q1 + q2) % mod;
  }
}
int main() {
  for (int i = 0; i < maxn; ++i) {
    int curval = 1;
    for (int j = 0; j < 7; ++j) {
      psum[j][i] = curval;
      if (i) psum[j][i] += psum[j][i - 1];
      curval = curval * (long long)i % mod;
    }
  }
  for (int i = 0; i < 7; ++i) comb[i][0] = 1;
  for (int i = 1; i < 7; ++i)
    for (int j = 1; j < 7; ++j)
      comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % mod;
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 0; i < 6; ++i) build(i, 0, 0, n);
  for (int i = 0; i < m; ++i) {
    char c = 0;
    while (c != '=' && c != '?') c = getchar();
    if (c == '=') {
      int fr, to, val;
      scanf("%d%d%d", &fr, &to, &val);
      for (int j = 0; j < 6; ++j) modify(j, 0, fr, to, val, 0, n);
    } else {
      int fr, to, k;
      scanf("%d%d%d", &fr, &to, &k);
      int shift = fr - 1;
      int answer = 0;
      int sg = 1;
      int st = 1;
      for (int j = k; j >= 0; --j) {
        int r = query(j, 0, fr, to, 0, n);
        r = ((long long)r * st) % mod * (long long)comb[k][j] % mod;
        if (sg == -1) r = (mod - r) % mod;
        (answer += r) %= mod;
        sg *= -1;
        st = st * (long long)shift % mod;
      }
      printf("%d\n", answer);
    }
  }
  return 0;
}
