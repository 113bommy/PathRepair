#include <bits/stdc++.h>
using namespace std;
int N, M, K;
int lt, rt;
int p[100005], sum[100005];
long long ans;
void Work() {
  int i, t, tmp = 0;
  memset(sum, 0, sizeof(sum));
  for (t = N / 2; t >= 1 && p[t] == p[N - t + 1]; t--)
    ;
  for (i = 1; i <= t; i++) {
    if ((++sum[p[i]]) == 0) tmp--;
    if ((--sum[p[N - i + 1]]) == -1) tmp++;
  }
  if (tmp == 0) {
    ans += (long long)K * (N - t + 1);
    return;
  }
  memset(sum, 0, sizeof(sum)), tmp = 0;
  for (i = 1; i <= N / 2; i++) sum[p[i]]++;
  for (i = N / 2 + 1; i <= N; i++)
    if ((--sum[p[i]]) == -1) tmp++;
  for (i = N / 2 + 1; i <= N; i++) {
    sum[p[i]] += 2;
    if (sum[p[i]] == 0 || sum[p[i]] == 1) tmp--;
    if (tmp == 0) break;
  }
  ans += (long long)K * (N - i + 1);
}
int main() {
  int i, j, tmp;
  scanf("%d", &N);
  for (i = 1; i <= N; i++) scanf("%d", &p[i]), sum[p[i]]++;
  for (i = 1, tmp = 0; i <= N; i++)
    if (sum[i] & 1) tmp++;
  if (tmp > 1) {
    puts("0");
    return 0;
  }
  for (K = 1; K * 2 <= N && p[K] == p[N - K + 1]; K++)
    ;
  if (K * 2 > N) {
    printf("%I64d\n", (long long)N * (N + 1) / 2);
    return 0;
  }
  for (i = K; i <= N - K + 1; i++) p[i - K + 1] = p[i];
  N -= (K - 1) * 2;
  Work();
  reverse(p + 1, p + 1 + N);
  Work();
  ans -= (long long)K * K;
  printf("%I64d\n", ans);
  return 0;
}
