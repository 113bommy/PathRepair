#include <bits/stdc++.h>
using namespace std;
long long K, ans;
long long pr[5005], tot;
long long p[5005], vis[5005];
long long cnt[305], have[30005];
void end() {
  int i;
  for (i = 1; i <= K; i++) printf("%I64d ", p[i]);
  printf("\n");
  exit(0);
}
void Find_Prime() {
  long long i, j;
  for (i = 2; i <= 300; i++) {
    if (!vis[i]) pr[++tot] = i;
    for (j = i * 2; j <= 300; j += i) vis[j] = 1;
  }
}
int main() {
  int i, j, t, k, s, tmp;
  long long now;
  scanf("%I64d", &K);
  Find_Prime();
  for (i = 1; i <= tot; i++)
    for (j = 1; j <= 10; j++) {
      memset(cnt, 0, sizeof(cnt));
      for (t = 1; t <= 10000; t++) {
        now = 1;
        while (now * pr[tmp = rand() % i + 1] <= 2 * K * K) {
          now *= pr[tmp];
          if (rand() % 100 > 80) break;
        }
        have[t] = now;
      }
      sort(have + 1, have + 1 + 30000),
          s = unique(have + 1, have + 1 + 30000) - have - 1;
      if (s < K) continue;
      for (t = 1, tmp = s; t <= K; t++)
        for (k = 1, s = p[t] = have[tmp - t + 1]; k <= i; k++)
          while (s % pr[k] == 0) cnt[k]++, s /= pr[k];
      for (k = 1; k <= i; k++)
        if (cnt[k] && cnt[k] < K / 2) break;
      if (k > i) end();
    }
  return 0;
}
