#include <bits/stdc++.h>
using namespace std;
const long long LLINF = 0x3f3f3f3f3f3f3f3fLL;
const int MAXK = 30;
long long fac[MAXK][2];
long long ans, clim, V;
int K;
long long cur_w;
long long X, Y, Z;
void dfs2(int p, long long cur) {
  if (p > K) {
    long long t = V / (cur_w * cur);
    long long val = t * cur_w * 2 + t * cur * 2 + cur_w * cur * 2;
    if (val < ans) {
      ans = val;
      X = cur_w, Y = cur, Z = t;
    }
    return;
  }
  int i;
  dfs2(p + 1, cur);
  for (i = 1; i <= fac[p][1]; i++) {
    cur *= fac[p][0];
    dfs2(p + 1, cur);
  }
}
void dfs1(int p, long long cur) {
  if (p > K) {
    long long t = floor(sqrt(V / cur));
    if (t * t * 2 + t * cur * 4 > ans) return;
    cur_w = cur;
    dfs2(1, 1);
    return;
  }
  long long buf[62];
  buf[0] = cur;
  int i;
  for (i = 1; i <= fac[p][1]; i++) {
    buf[i] = (cur *= fac[p][0]);
    if (cur > clim) break;
  }
  for (i--; i >= 0; i--) {
    fac[p][1] -= i;
    dfs1(p + 1, buf[i]);
    fac[p][1] += i;
  }
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    V = 1;
    scanf("%d", &K);
    long long a, b;
    for (int i = 1; i <= K; i++) {
      scanf("%I64d%I64d", &a, &b);
      fac[i][0] = a, fac[i][1] = b;
      for (int j = 1; j <= b; j++) V *= a;
    }
    ans = LLINF;
    clim = round(pow(V, 0.34));
    dfs1(1, 1);
    printf("%I64d %I64d %I64d %I64d\n", ans, X, Y, Z);
  }
}
