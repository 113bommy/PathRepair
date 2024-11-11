#include <bits/stdc++.h>
using namespace std;
int N, M, K, comb[128][128], D[128][128];
long long nr[128];
int cnt[128][128 * 128];
int add(int a, int b) {
  a += b;
  if (a >= 1000000007) a -= 1000000007;
  return a;
}
int put(int a, long long b) {
  if (b == 1) return a;
  if (b % 2 == 0) {
    int c = put(a, b / 2);
    return (int)((long long)c * c % 1000000007);
  }
  int c = put(a, b - 1);
  return (int)((long long)c * a % 1000000007);
}
void preproc(void) {
  int i, j, k;
  for (comb[1][0] = comb[1][1] = 1, i = 2; i <= N; i++)
    for (comb[i][0] = 1, j = 1; j <= i; j++)
      comb[i][j] = add(comb[i - 1][j], comb[i - 1][j - 1]);
  for (i = 1; i <= N; i++) nr[i] = (M - i) / N + 1;
  for (i = 1; i <= N; i++)
    for (j = 0; j <= N; j++) D[i][j] = put(comb[N][j], nr[i]);
}
int main(void) {
  cin >> N >> M >> K;
  int i, j, k, n, p1;
  preproc();
  cnt[0][0] = 1;
  for (n = 1; n <= N; n++)
    for (k = 0; k <= K && k <= n * N; k++)
      for (p1 = 0; p1 <= N && k - p1 >= 0; p1++) {
        int a = (int)((long long)cnt[n - 1][k - p1] * D[n][p1] % 1000000007);
        cnt[n][k] += a;
        if (cnt[n][k] >= 1000000007) cnt[n][k] -= 1000000007;
      }
  cout << cnt[N][K];
  return 0;
}
