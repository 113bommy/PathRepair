#include <bits/stdc++.h>
const int maxn = 200001;
const int maxm = 1000001;
const long long mod = 1e9 + 7;
struct D {
  int cnt[maxm];
  int N;
  void div(int n) {
    int lim = sqrt(n);
    for (int i = 2; i <= lim; i++)
      if (n % i == 0) {
        cnt[i]++;
        cnt[n / i]++;
      }
    if (lim * lim == n) cnt[lim]--;
    cnt[n]++;
  }
  void init() {
    scanf("%d", &N);
    for (int i = 1, t; i <= N; i++) {
      scanf("%d", &t);
      if (t == 1) continue;
      div(t);
    }
  }
  long long qp(int a, int b) {
    long long now = a, ans = 1;
    while (b) {
      if (b % 2) ans = ans * now % mod;
      now = now * now % mod;
      b /= 2;
    }
    return ans;
  }
  void work() {
    long long ans = 0;
    for (int i = 2; i < maxm; i++) {
      if (cnt[i] == 0) continue;
      cnt[i] = cnt[i] * qp(2, cnt[i] - 1) % mod;
    }
    for (int i = maxm - 1; i > 1; i--) {
      for (int j = i + i; j < maxm; j += i)
        cnt[i] = (cnt[i] - cnt[j] + mod) % mod;
      ans = (ans + cnt[i] * i % mod) % mod;
    }
    printf("%I64d\n", ans);
  }
} sol;
int main() {
  sol.init();
  sol.work();
  return 0;
}
