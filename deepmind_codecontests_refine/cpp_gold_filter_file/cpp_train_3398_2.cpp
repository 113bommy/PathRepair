#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000000 + 100;
const long long INF = 1e18;
int N, M, A[20];
long long K, B[2][maxn];
void dfs(int l, int r, long long sum, int f) {
  if (sum > INF) return;
  B[f][++B[f][0]] = sum;
  for (int i = l; i <= r; ++i)
    if (sum <= INF / A[i]) dfs(i, r, sum * (long long)A[i], f);
}
bool check(long long k) {
  long long cnt = 0;
  for (int i = B[0][0], j = 0; i >= 1; --i) {
    while (j < B[1][0] && B[1][j + 1] <= k / B[0][i]) j++;
    cnt += j;
  }
  return cnt < K;
}
void Init() {
  scanf("%d", &N);
  M = min(N >> 1, 6);
  for (int i = 1; i <= N; ++i) scanf("%d", &A[i]);
  scanf("%lld", &K);
}
void Solve() {
  B[0][0] = B[1][0] = 0;
  dfs(1, M, 1ll, 0), dfs(M + 1, N, 1ll, 1);
  sort(B[0] + 1, B[0] + B[0][0] + 1);
  sort(B[1] + 1, B[1] + B[1][0] + 1);
  long long l = 0, r = INF;
  while (l <= r) {
    long long mid = (l + r) >> 1;
    if (check(mid))
      l = mid + 1;
    else
      r = mid - 1;
  }
  printf("%I64d\n", l);
}
int main() { Init(), Solve(); }
