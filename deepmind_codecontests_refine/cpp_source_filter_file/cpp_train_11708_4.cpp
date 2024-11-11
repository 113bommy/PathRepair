#include <bits/stdc++.h>
using namespace std;
void ga(int N, int *A) {
  for (int i(0); i < N; i++) scanf("%d", A + i);
}
char s[10][64];
int X[10], N, M, C[10];
bool fl(int u, int *C) {
  for (int i(0); i < M; i++)
    if (N - u < X[i] - C[i] || C[i] > X[i]) return 1;
  return 0;
}
long long HH(int *C) {
  long long H = 0;
  for (int i(0); i < M; i++) H *= 36, H += C[i];
  return H;
}
unordered_map<long long, long long> dp[36];
long long go(int u, int *C) {
  if (fl(u, C)) return 0;
  if (u == N) return 1;
  long long H = HH(C), v = 0;
  if (dp[u].count(H)) return dp[u][H];
  for (int k(48); k < 50; k++) {
    for (int i(0); i < M; i++) C[i] += s[i][u] != k;
    v += go(u + 1, C);
    for (int i(0); i < M; i++) C[i] -= s[i][u] != k;
  }
  return dp[u][H] = v;
}
int main(void) {
  scanf("%d%d", &N, &M);
  for (int i(0); i < N; i++) scanf("%s%d", s[i], X + i);
  printf("%lld\n", go(0, C));
  return 0;
}
