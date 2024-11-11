#include <bits/stdc++.h>
using namespace std;
int n, m, nw, ff, tot, ty[262144], w[262144], F[262144], Q[262144], rk[262144],
    si[262144], s[262144];
vector<int> e[262144];
int L[262144 * 2], R[262144 * 2];
long long ls, a[262144 * 2], b[262144 * 2];
long long ny(int x) {
  if (x == 1) return 1;
  long long y = 1000000007 / x + 1;
  return ny(x * y - 1000000007) * y % 1000000007;
}
inline void dw(int x) {
  a[x * 2 + 1] = a[x * 2 + 1] * b[x] % 1000000007;
  b[x * 2 + 1] = b[x * 2 + 1] * b[x] % 1000000007;
  a[x * 2] = a[x * 2] * b[x] % 1000000007;
  b[x * 2] = b[x * 2] * b[x] % 1000000007;
  b[x] = 1;
}
inline void up(int x) { a[x] = (a[x * 2] + a[x * 2 + 1]) % 1000000007; }
void f(int x, int y, int l, int r) {
  if (L[x] == l && R[x] == r) {
    a[x] = a[x] * y % 1000000007;
    b[x] = b[x] * y % 1000000007;
    return;
  }
  dw(x);
  if (r <= R[x * 2]) {
    f(x * 2, y, l, r);
    up(x);
    return;
  }
  if (l >= L[x * 2 + 1]) {
    f(x * 2 + 1, y, l, r);
    up(x);
    return;
  }
  f(x * 2, y, l, R[x * 2]);
  f(x * 2 + 1, y, L[x * 2 + 1], r);
  up(x);
}
void g(int x, int y, int z) {
  if (L[x] == y && R[x] == y) {
    a[x] = b[x] * z % 1000000007;
    return;
  }
  dw(x);
  if (y <= R[x * 2])
    g(x * 2, y, z);
  else
    g(x * 2 + 1, y, z);
  up(x);
}
long long q(int x, int l, int r) {
  if (L[x] == l && R[x] == r) return a[x];
  dw(x);
  if (r <= R[x * 2]) return q(x * 2, l, r);
  if (l >= L[x * 2 + 1]) return q(x * 2 + 1, l, r);
  return (q(x * 2, l, R[x * 2]) + q(x * 2 + 1, L[x * 2 + 1], r)) % 1000000007;
}
void dfs(int x) {
  int sz = e[x].size() - 1;
  rk[x] = ++tot;
  si[x] = 1;
  for (int i = (0); i <= (sz); i++) {
    int tt = e[x][i];
    dfs(tt);
    si[x] += si[tt];
  }
}
int main() {
  scanf("%d%d", &w[1], &m);
  n = 1;
  for (int i = (1); i <= (m); i++) {
    scanf("%d", &ty[i]);
    if (ty[i] == 1) {
      n++;
      scanf("%d%d", &F[n], &w[n]);
    } else
      scanf("%d", &Q[i]);
  }
  for (int i = (2); i <= (n); i++) e[F[i]].push_back(i);
  for (int i = (1); i <= (262144 * 2 - 1); i++) b[i] = 1;
  L[1] = 1;
  R[1] = 262144;
  for (int i = (1); i <= (262144 - 1); i++) {
    L[i * 2] = L[i];
    R[i * 2] = (L[i] + R[i]) / 2;
    L[i * 2 + 1] = R[i * 2] + 1;
    R[i * 2 + 1] = R[i];
  }
  for (int i = (1); i <= (n); i++) s[i] = 1;
  dfs(1);
  g(1, 1, w[1]);
  nw = 1;
  for (int i = (1); i <= (m); i++)
    if (ty[i] == 1) {
      nw++;
      ff = F[nw];
      s[nw] = 1;
      ls = ny(s[ff]);
      s[ff]++;
      g(1, rk[nw], w[nw]);
      f(1, ls * s[ff] % 1000000007, rk[ff], rk[ff] + si[ff] - 1);
    } else {
      ff = F[Q[i]];
      if (ff)
        ls = ny(q(1, rk[ff], rk[ff])) * w[ff] % 1000000007;
      else
        ls = 1;
      printf("%I64d\n",
             q(1, rk[Q[i]], rk[Q[i]] + si[Q[i]] - 1) * ls % 1000000007);
    }
}
