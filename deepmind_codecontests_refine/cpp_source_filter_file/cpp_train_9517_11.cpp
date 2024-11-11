#include <bits/stdc++.h>
using namespace std;
long long rmq[19][(1 << 20)];
long long DP[200005];
long long n;
void RMQ() {
  for (int i = 0; i < n; ++i) rmq[0][i] = DP[i];
  for (int k = 1; k <= 19; ++k)
    for (int i = 0; i + (1 << k) <= n; ++i)
      rmq[k][i] = min(rmq[k - 1][i], rmq[k - 1][i + (1 << (k - 1))]);
}
long long query(int x, int y) {
  int k = 31 - __builtin_clz(y - x + 1);
  return min(rmq[k][x], rmq[k][y + 1 - (1 << k)]);
}
int main() {
  int m, d, a, b, t, T;
  long long S;
  while (scanf("%d", &n) == 1) {
    scanf("%d", &m), scanf("%d", &d);
    T = 1;
    S = 0;
    memset(DP, 0, sizeof(DP));
    while (m--) {
      cin >> a >> b >> t;
      S += b;
      a--;
      RMQ();
      for (long long j = 0; j < n; ++j)
        DP[j] = abs(a - j) + query(max(0LL, j - (long long)(t - T) * d),
                                   min(j + (long long)(t - T) * d, n));
      T = t;
    }
    cout << S - *min_element(DP, DP + n) << '\n';
  }
}
