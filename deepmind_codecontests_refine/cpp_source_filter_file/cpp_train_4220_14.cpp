#include <bits/stdc++.h>
using namespace std;
int gi() {
  int res = 0, w = 1;
  char ch = getchar();
  while (ch != '-' && !isdigit(ch)) ch = getchar();
  if (ch == '-') w = -1, ch = getchar();
  while (isdigit(ch)) res = res * 10 + ch - '0', ch = getchar();
  return res * w;
}
using LL = long long;
const LL INF = 1e16;
void chkmin(LL &x, LL y) {
  if (x > y) x = y;
}
const int MAX_N = 1e5 + 5;
int N, M, r[10][MAX_N], c[10][MAX_N];
LL f[1 << 5];
int main() {
  N = gi(), M = gi();
  for (int i = 1; i < M; i++)
    for (int j = 0; j < N; j++) r[j][i] = gi();
  for (int i = 1; i <= M; i++)
    for (int j = 0; j < N; j++) c[j][i] = gi();
  for (int i = 0; i < 1 << N; i++) f[i] = INF;
  f[0] = 0;
  for (int i = 1; i < M; i++) {
    for (int s = 0; s < 1 << N; s++)
      for (int j = 0; j < N; j++)
        if (!(s >> j & 1)) chkmin(f[s | 1 << j], f[s] + r[j][i]);
    for (int s = 0; s < 1 << N; s++)
      for (int j = 0; j < N; j++)
        if ((s >> j & 1) != (s >> ((j + 1) % N) & 1)) f[s] += c[j][i];
  }
  printf("%lld\n", f[(1 << N) - 1]);
  return 0;
}
