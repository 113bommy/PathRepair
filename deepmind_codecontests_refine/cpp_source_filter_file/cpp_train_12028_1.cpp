#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
const int Base = 2e9 + 1000;
int n, K;
long long a, b;
long long val[N];
priority_queue<long long> que;
int main() {
  cin >> n >> K >> a >> b;
  for (int i = 1; i <= n; i++) scanf("%lld", &val[i]), val[i] += Base;
  sort(val + 1, val + 1 + n);
  if (5 * b <= a) {
    long long ans = 1LL << 60;
    long long sum = 0;
    for (int i = 1; i <= K; i++) sum += (val[K] - val[1]) * b;
    ans = sum;
    for (int i = 1; i + K <= n; i++) {
      sum -= (val[i + K - 1] - val[i]) * b;
      sum += (val[i + K] - val[i + K - 1]) * (K - 1) * b;
      ans = min(ans, sum);
    }
    printf("%lld\n", ans);
  } else {
    long long ans = 1LL << 60;
    for (int m = 0; m < 5; m++) {
      while (!que.empty()) que.pop();
      long long sum = 0;
      for (int i = 1; i <= n; i++) {
        long long to = 0;
        if (val[i] % 5 <= m)
          to = val[i] / 5 * 5 + m;
        else
          to = (val[i] / 5 + 1) * 5 + m;
        que.push((to - val[i]) * b - (to - m) / 5 * a);
        sum += (to - val[i]) * b - (to - m) / 5 * a;
        while (que.size() > K) {
          sum -= que.top();
          que.pop();
        }
        if (que.size() == K) ans = min(ans, sum + (to - m) / 5 * a * K);
      }
    }
    printf("%lld\n", ans);
  }
}
