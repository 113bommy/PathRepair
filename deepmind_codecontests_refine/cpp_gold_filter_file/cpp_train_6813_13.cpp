#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7, M = 1e6 + 7;
int row[N], col[N];
long long dpc[M], dpr[M];
int main() {
  priority_queue<int> pqc, pqr;
  int n, m, k, p;
  scanf("%d %d %d %d", &n, &m, &k, &p);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int a;
      scanf("%d", &a);
      row[i] += a;
      col[j] += a;
      if (i == n - 1) {
        pqc.push(col[j]);
      }
    }
    pqr.push(row[i]);
  }
  for (int i = 1; i <= k; i++) {
    dpr[i] = pqr.top() + dpr[i - 1];
    pqr.push(pqr.top() - p * m);
    pqr.pop();
    dpc[i] = pqc.top() + dpc[i - 1];
    pqc.push(pqc.top() - p * n);
    pqc.pop();
  }
  long long ans = -1e18;
  for (int i = 0; i <= k; i++) {
    ans = max(ans, 1ll * dpr[i] + dpc[k - i] - (1ll * i * (k - i) * p));
  }
  printf("%lld", ans);
}
