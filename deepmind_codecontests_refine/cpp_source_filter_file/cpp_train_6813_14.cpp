#include <bits/stdc++.h>
using namespace std;
const int N = 1050;
priority_queue<long long> X, Y;
int n, m;
long long x[N], y[N];
long long tgx, tgy;
long long fx[N * N], fy[N * N];
int q, p;
int main() {
  scanf("%d%d%d%d", &n, &m, &q, &p);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      int g;
      scanf("%d", &g);
      x[i] += g;
      y[j] += g;
    }
  for (int i = 1; i <= n; i++) X.push(x[i]);
  for (int i = 1; i <= q; i++) {
    fx[i] = X.top();
    X.pop();
    X.push(fx[i] - m * p);
    fx[i] += fx[i - 1];
  }
  for (int i = 1; i <= m; i++) Y.push(y[i]);
  for (int i = 1; i <= q; i++) {
    fy[i] = Y.top();
    Y.pop();
    Y.push(fy[i] - n * p);
    fy[i] += fy[i - 1];
  }
  long long ans = -(1ll << 62);
  for (int i = 1; i <= q; i++) {
    long long get = fx[i] + fy[q - i] - 1ll * i * (q - i) * p;
    if (get > ans) ans = get;
  }
  printf("%I64d\n", ans);
}
