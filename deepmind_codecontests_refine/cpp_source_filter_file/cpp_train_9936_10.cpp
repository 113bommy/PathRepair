#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void read(T& x) {
  bool fu = 0;
  char c;
  for (c = getchar(); c <= 32; c = getchar())
    ;
  if (c == '-') fu = 1, c = getchar();
  for (x = 0; c > 32; c = getchar()) x = x * 10 + c - '0';
  if (fu) x = -x;
};
template <class T>
inline void read(T& x, T& y) {
  read(x);
  read(y);
}
template <class T>
inline void read(T& x, T& y, T& z) {
  read(x);
  read(y);
  read(z);
}
inline char getc() {
  char c;
  for (c = getchar(); c <= 32; c = getchar())
    ;
  return c;
}
const int N = 100010;
int edge, e[N << 1], b[N << 1], fir[N];
void add(int x, int y) {
  e[++edge] = y;
  b[edge] = fir[x];
  fir[x] = edge;
}
int n, m, m0, K, i, j, k, l, x, y, z;
int st[N], sz[N], d[N], v[N];
bool done[N];
long long r[N], r2[N], c[N], ic[N];
vector<int> F[N], B[N], R1[N], R2[N];
vector<pair<int, int> > S1[N], S2[N];
vector<pair<int, int> >::iterator pos;
void dfs(int i, int f) {
  st[++st[0]] = i;
  sz[i] = 1;
  d[i] = d[f] + 1;
  r[i] = (r[f] + v[i] * c[d[i]]) % m;
  r2[i] = (r2[f] * K + v[i]) % m;
  for (int k = fir[i]; k; k = b[k])
    if (!done[e[k]] && e[k] != f) dfs(e[k], i), sz[i] += sz[e[k]];
}
void work(int now) {
  int i, j, k, sz0, res, best = N, tot;
  st[0] = 0;
  dfs(now, 0);
  sz0 = sz[now];
  for (int pos = (1); pos <= (st[0]); pos++) {
    i = st[pos];
    res = sz0 - sz[i];
    for (k = fir[i]; k; k = b[k])
      if (sz[e[k]] < sz[i]) res = max(res, sz[e[k]]);
    if (res < best) best = res, now = i;
  }
  F[now].push_back(now);
  B[now].push_back(now);
  R1[now].push_back(v[now]);
  S1[now].push_back(make_pair(m0, now));
  R2[now].push_back(m0);
  S2[now].push_back(make_pair(v[now], now));
  done[now] = 1;
  for (k = fir[now]; k; k = b[k])
    if (!done[e[k]]) {
      st[0] = 0;
      dfs(e[k], 0);
      for (int pos = (1); pos <= (st[0]); pos++) {
        i = st[pos];
        r[i] = (r[i] + v[now]) % m;
        int tt = 1LL * (m0 - r2[i] + m) * ic[d[i]] % m;
        F[i].push_back(now);
        B[i].push_back(e[k]);
        R1[i].push_back(r[i]);
        S1[now].push_back(make_pair(tt, e[k]));
        R2[i].push_back(tt);
        S2[now].push_back(make_pair(r[i], e[k]));
      }
    }
  sort(S1[now].begin(), S1[now].end());
  sort(S2[now].begin(), S2[now].end());
  for (k = fir[now]; k; k = b[k])
    if (!done[e[k]]) work(e[k]);
}
long long pow(long long a, long long b, long long c) {
  long long ans = 1;
  for (a %= c; b; b >>= 1, a = a * a % c)
    if (b & 1) ans = ans * a % c;
  return ans;
}
int main() {
  read(n, m);
  read(K, m0);
  c[0] = 1;
  for (i = 1; i <= n; i++) c[i] = c[i - 1] * K % m;
  for (i = 0; i <= n; i++) ic[i] = pow(c[i], m - 2, m);
  for (i = 1; i <= n; i++) read(v[i]);
  for (i = 1; i <= n - 1; i++) read(x, y), add(x, y), add(y, x);
  work(1);
  long long tot = 0;
  for (i = 1; i <= n; i++) {
    long long in0 = 0, out0 = 0, in1 = 0, out1 = 0;
    for (j = 0; j < F[i].size(); j++) {
      int u = F[i][j], bb = B[i][j], rr1 = R1[i][j], rr2 = R2[i][j];
      in1 += (upper_bound(S1[u].begin(), S1[u].end(), make_pair(rr1, N)) -
              lower_bound(S1[u].begin(), S1[u].end(), make_pair(rr1, 0))) -
             (upper_bound(S1[u].begin(), S1[u].end(), make_pair(rr1, bb)) -
              lower_bound(S1[u].begin(), S1[u].end(), make_pair(rr1, bb)));
      out1 += (upper_bound(S2[u].begin(), S2[u].end(), make_pair(rr2, N)) -
               lower_bound(S2[u].begin(), S2[u].end(), make_pair(rr2, 0))) -
              (upper_bound(S2[u].begin(), S2[u].end(), make_pair(rr2, bb)) -
               lower_bound(S2[u].begin(), S2[u].end(), make_pair(rr2, bb)));
    }
    in0 = n - 1 - in1;
    out0 = n - 1 - out1;
    if (v[i] == m0)
      in1++, out1++;
    else
      in0++, out0++;
    tot += 2 * out0 * out1 + 2 * in0 * in1 + out0 * in1 + out1 * in0;
  }
  tot = n * n * n - tot / 2;
  cout << tot << endl;
  return 0;
}
