#include <bits/stdc++.h>
using namespace std;
int dx[10010], dy[10010];
int __ABS(int A) {
  if (A > 0) return A;
  return -A;
}
int main(void) {
  int N, M, K;
  int nowx, nowy;
  scanf("%d%d%d%d%d", &N, &M, &nowx, &nowy, &K);
  for (int i = 0; i < K; i++) scanf("%d%d", &dx[i], &dy[i]);
  long long int ans = 0;
  for (int i = 0; i < K; i++) {
    int xstep, ystep;
    xstep = ystep = 20000000;
    if (dx[i] > 0) xstep = (N - nowx) / dx[i];
    if (dx[i] < 0) xstep = (nowx - 1) / __ABS(dx[i]);
    if (dy[i] > 0) ystep = (M - nowy) / dy[i];
    if (dy[i] < 0) ystep = (nowy - 1) / __ABS(dy[i]);
    if (xstep < ystep) {
      ans += xstep;
      nowx += dx[i] * xstep;
      nowy += dy[i] * xstep;
    } else {
      ans += ystep;
      nowx += dx[i] * ystep;
      nowy += dy[i] * ystep;
    }
  }
  printf("%I64d\n", ans);
  return 0;
}
