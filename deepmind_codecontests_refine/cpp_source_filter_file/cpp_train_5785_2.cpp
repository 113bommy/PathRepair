#include <bits/stdc++.h>
using namespace std;
const int N = 2100;
const int M = 200010;
const int p = 1000000007;
int r[N], c[N], n, m, k, S, id[N];
long long f[N][22], C[N][N], jie[M], rev[M], two[22], P, Q;
bool bad[N], con[N][N];
long long fast(long long x, int k) {
  long long ans = 1;
  for (; k; k >>= 1) {
    if (k & 1) ans = ans * x % p;
    x = x * x % p;
  }
  return ans;
}
void init() {
  int i, j;
  for (jie[0] = 1, i = 1; i < M; ++i) jie[i] = jie[i - 1] * i % p;
  rev[M - 1] = fast(jie[M - 1], p - 2);
  for (i = M - 2; i >= 0; --i) rev[i] = rev[i + 1] * (i + 1) % p;
  for (two[0] = 1, i = 1; i < 22; ++i) two[i] = (two[i - 1] << 1) % p;
}
inline bool cmp(int a, int b) { return r[a] + c[a] < r[b] + c[b]; }
inline void calc(int x, int y) {
  if (r[y] >= r[x] && c[y] >= c[x])
    con[x][y] = 1;
  else
    return;
  C[x][y] = jie[r[y] + c[y] - r[x] - c[x]];
  C[x][y] = C[x][y] * rev[r[y] - r[x]] % p * rev[c[y] - c[x]] % p;
}
int main() {
  ios ::sync_with_stdio(false);
  int i, j, x, y, tmp, ii, jj;
  cin >> n >> m >> k >> S;
  init();
  for (i = 1; i <= k; ++i) cin >> r[i] >> c[i], id[i] = i;
  sort(id + 1, id + 1 + k, cmp);
  int s = 1, t = k;
  if (r[id[1]] != 1 || c[id[1]] != 1) id[s = 0] = 0, r[s] = c[s] = 1;
  if (r[id[k]] != n || c[id[k]] != m) id[t = k + 1] = t, r[t] = n, c[t] = m;
  for (i = 1; i <= k; ++i) bad[i] = 1;
  for (i = s; i < t; ++i) {
    for (j = i + 1; j <= t; ++j) calc(id[i], id[j]);
  }
  if (bad[t])
    f[t][1] = 1;
  else
    f[t][0] = 1;
  for (i = t - 1; i >= s; --i) {
    x = id[i];
    tmp = bad[x];
    for (j = 0; j <= 20; ++j) {
      if (j == 0 && bad[x]) continue;
      f[i][j] = C[x][id[t]];
      for (ii = i + 1; ii <= t; ++ii) {
        y = id[ii];
        if (con[x][y]) {
          f[i][j] -= C[x][y] * f[ii][j + 1 - tmp] % p;
          (f[i][j] += p) %= p;
        }
      }
      for (jj = j - 1; jj >= 0; --jj) ((f[i][j] -= f[i][jj]) += p) %= p;
    }
  }
  for (tmp = C[id[s]][id[t]], i = 0; i <= 20; ++i) {
    x = S / two[i] + (S % two[i] != 0);
    (P += f[s][i] * 1LL * x % p) %= p;
    (tmp -= f[s][i] + p) %= p;
  }
  (P += tmp) %= p, Q = C[id[s]][id[t]];
  cout << (P * fast(Q, p - 2) % p) << endl;
  return 0;
}
