#include <bits/stdc++.h>
using namespace std;
long long s[5010], sum[5010], ans = -1e15;
int dp1[5010], dp2[5010], N, ans2;
int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf("%lld", s + i);
  sum[0] = s[0];
  for (int i = 1; i < N; i++) sum[i] = sum[i - 1] + s[i];
  dp1[0] = 0;
  dp1[1] = (s[0] >= 0);
  for (int i = 2; i <= N; i++) {
    if (sum[dp1[i - 1] - 1] < sum[i - 1])
      dp1[i] = i;
    else
      dp1[i] = dp1[i - 1];
  }
  dp2[N - 1] = N - (s[N - 1] < 0);
  dp2[N] = N;
  for (int i = N - 2; i >= 0; i--) {
    if (sum[dp2[i + 1] - 1] < sum[i - 1])
      dp2[i] = i;
    else
      dp2[i] = dp2[i + 1];
  }
  for (int i = 0; i <= N; i++) {
    int now =
        sum[dp1[i] - 1] * 2 - sum[i - 1] * 2 + sum[dp2[i] - 1] * 2 - sum[N - 1];
    if (ans < now) {
      ans = now, ans2 = i;
    }
  }
  printf("%d %d %d\n", dp1[ans2], ans2, dp2[ans2]);
  return 0;
}
