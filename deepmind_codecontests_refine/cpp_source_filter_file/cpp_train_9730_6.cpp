#include <bits/stdc++.h>
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast", "unroll-loops", "omit-frame-pointer", "inline")
#pragma GCC option("arch=native", "tune=native", "no-zero-upper")
#pragma GCC target("avx2")
using namespace std;
const long long INF = 1e16;
const int maxn = 2e6 + 7;
const int mod = 1e9 + 7;
inline bool read(long long &num) {
  char in;
  bool IsN = false;
  in = getchar();
  if (in == EOF) return false;
  while (in != '-' && (in < '0' || in > '9')) in = getchar();
  if (in == '-') {
    IsN = true;
    num = 0;
  } else
    num = in - '0';
  while (in = getchar(), in >= '0' && in <= '9') {
    num *= 10, num += in - '0';
  }
  if (IsN) num = -num;
  return true;
}
long long n, m, c;
int C[maxn], t[maxn];
string s[105];
int N, L;
double p[maxn], dp[maxn];
long long bitcount(long long x) {
  int cot = 0;
  while (x) {
    cot++;
    x -= x & -x;
  }
  return cot;
}
void work() {
  L = s[1].size();
  N = 1 << L;
  for (int i = 1; i <= n; i++) {
    for (int k = i + 1; k <= n; k++) {
      long long staus = 0;
      for (int j = 0; j < L; j++) staus |= (s[i][j] == s[k][j]) << j;
      t[staus] |= (1ll << i | 1ll << k);
    }
  }
  for (int i = N - 1; i >= 0; i--) {
    for (int k = 0; k < L; k++) {
      if (i >> k & 1ll) t[i ^ (1ll << k)] |= t[i];
    }
    C[i] = bitcount(t[i]);
  }
}
int main() {
  read(n);
  if (n == 1) {
    printf("1.000000000\n");
    return 0;
  }
  for (int i = 1; i <= n; i++) cin >> s[i];
  work();
  dp[0] = 1;
  for (int i = 0; i < N; i++) {
    int bit = bitcount(i), cot = L - bit;
    if (!C[i]) continue;
    for (int k = 0; k < L; k++) {
      if (i >> k & 1ll) continue;
      dp[i | (1ll << k)] += 1.0 * dp[i] / cot * C[i | (1ll << k)] / C[i];
      p[bit + 1] += 1.0 * dp[i] / cot * (C[i] - C[i | (1ll << k)]) / C[i];
    }
  }
  double ans = 0;
  for (int i = 1; i <= L; i++) {
    ans += p[i] * i;
  }
  printf("%.9lf\n", ans);
  return 0;
}
