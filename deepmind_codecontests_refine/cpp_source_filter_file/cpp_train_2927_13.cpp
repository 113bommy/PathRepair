#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int INF = 1e9 + 1000;
int N, S, M, K;
int segment_start[3000];
int A[3000];
int pref[3000];
int DP[3000][3000];
bool can(int x) {
  pref[0] = 0;
  for (int i = (1); i < (N + 1); ++i) pref[i] = pref[i - 1] + (A[i - 1] <= x);
  for (int i = 0; i < (M + 1); ++i) DP[0][i] = 0;
  for (int i = (1); i < (N + 1); ++i)
    for (int j = 0; j < (M + 1); ++j) {
      DP[i][j] = DP[i - 1][j];
      if (j > 0 && segment_start[i] < i)
        DP[i][j] = max(DP[i][j], DP[segment_start[i]][j - 1] + pref[i] -
                                     pref[segment_start[i]]);
    }
  return DP[N][M] >= K;
}
int main() {
  scanf("%d%d%d%d", &N, &S, &M, &K);
  for (int i = 0; i < (N + 1); ++i) segment_start[i] = INF;
  for (int i = 0; i < (N); ++i) scanf("%d", &A[i]);
  for (int i = 0; i < (S); ++i) {
    int l, r;
    scanf("%d%d", &l, &r);
    --l, --r;
    segment_start[r + 1] = min(segment_start[r], l);
  }
  for (int i = (N)-1; i >= (0); --i)
    segment_start[i] = min(segment_start[i], segment_start[i + 1]);
  int L = 0, R = 1e9 + 100;
  while (L < R) {
    int mid = (L + R) / 2;
    if (can(mid)) {
      R = mid;
    } else {
      L = mid + 1;
    }
  }
  if (L > 1e9) L = -1;
  printf("%d\n", L);
}
