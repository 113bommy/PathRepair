#include <bits/stdc++.h>
using namespace std;
long long N, M, K, a, b, c, t, tt, ans, P;
long long num[100007], cnt[100007];
int main() {
  scanf("%I64d%I64d", &N, &K);
  long long ans = 0;
  if (K == 2) {
    for (int i = 1; i <= N; i++) {
      scanf("%I64d", &a);
      for (long long j = 2; j * j <= a; j++)
        if (a % (j * j) == 0) a /= j * j;
      cnt[a]++;
    }
    for (int i = 1; i <= 100000; i++) ans += cnt[i] * (cnt[i] - 1) / 2;
  } else {
    for (int i = 1; i <= N; i++) {
      scanf("%I64d", &a);
      cnt[a]++;
    }
    for (int i = 1; i <= 100001; i++) {
      long long ji = 1;
      for (int j = 1; j <= K; j++) {
        ji *= i;
        if (ji > 1e10) break;
      }
      num[i] = ji;
      if (ji > 1e10) {
        t = i - 1;
        break;
      }
    }
    for (int i = 1; i <= t; i++) {
      for (long long j = 1; j * j <= num[i]; j++)
        if (num[i] % j == 0) {
          if (j * j < num[i] && num[i] / j <= 100000)
            ans += cnt[j] * cnt[num[i] / j];
          else if (j * j == num[i])
            ans += cnt[j] * (cnt[j] - 1) / 2;
        }
    }
  }
  printf("%I64d\n", ans);
  return 0;
}
