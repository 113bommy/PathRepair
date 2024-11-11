#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
int T;
int n, k;
long long A;
long long h;
int cnt[6] = {1, 1, 2, 4, 8, 16}, p[125];
int rk[6];
long long a[7], AA[25];
bool in[10][125];
long long qpow(long long a, long long b) {
  long long r = 1;
  while (b) {
    if (b & 1) r = r * a % mod;
    b >>= 1;
    a = a * a % mod;
  }
  return r;
}
void dfs(int x, int last, int c) {
  if (x == k) {
    for (int i = 0; i < n; ++i)
      if (!in[x][i >> k - x]) {
        p[i] = rk[x];
      }
    long long w = 0;
    for (int i = 0; i < n; ++i) w += AA[p[i]] * (i + 1);
    w %= mod;
    if (w == h) {
      for (int i = 0; i < n; ++i) printf("%d ", p[i]);
      printf("\n");
      exit(0);
    }
    return;
  }
  if (x == 4) {
    static int q[9];
    q[0] = 0;
    for (int i = 0; i < n; ++i) {
      if (!in[5][i]) {
        if (i % 2 == 1 || in[5][i + 1])
          p[i] = rk[x + 1];
        else {
          q[++q[0]] = i;
          p[i] = rk[x];
          p[i + 1] = rk[x + 1];
          ++i;
        }
      }
    }
    long long w = 0;
    for (int i = 0; i < n; ++i) w += AA[p[i]] * (i + 1);
    w %= mod;
    long long det = (a[5] - a[6] + mod) % mod;
    for (int i = 1; i <= 8; ++i)
      if ((w + det * i) % mod == h) {
        for (int j = 0; j < i; ++j) swap(p[q[j]], p[q[j] + 1]);
        for (int i = 0; i < n; ++i) printf("%d ", p[i]);
        printf("\n");
        exit(0);
      }
    return;
  }
  for (int i = last; i < n; ++i)
    if (!in[x][i >> k - x]) {
      p[i] = rk[x];
      for (int t = x; t <= k; ++t) in[t][i >> k - t] = 1;
      if (c == cnt[x])
        dfs(x + 1, 0, 1);
      else
        dfs(x, i + 1, c + 1);
      p[i] = 0;
      for (int t = x; t <= k; ++t) in[t][i >> k - t] = 0;
    }
}
int main() {
  cin >> k >> A >> h;
  AA[1] = a[1] = qpow(A, rk[0] = 1);
  AA[2] = a[2] = qpow(A, rk[1] = 2);
  AA[3] = a[3] = qpow(A, rk[2] = 3);
  AA[5] = a[4] = qpow(A, rk[3] = 5);
  AA[9] = a[5] = qpow(A, rk[4] = 9);
  AA[17] = a[6] = qpow(A, rk[5] = 17);
  n = 1 << k;
  dfs(0, 0, 1);
  puts("-1");
}
