#include <bits/stdc++.h>
using namespace std;
const long long INF = (1LL << 60);
priority_queue<long long> pqr, pqc;
int sum_r[1005], sum_c[1005], k, p;
long long row[1000001], col[1000001];
void cal(int cnt, priority_queue<long long> pq, long long res[1000001]) {
  long long ans = 0;
  for (int i = 1; i <= k; i++) {
    long long tmp = pq.top();
    pq.pop();
    pq.push(tmp - cnt * 1LL * p);
    ans += tmp;
    res[i] = ans;
  }
  res[0] = 0;
}
int main() {
  int n, m;
  scanf("%d%d%d%d", &n, &m, &k, &p);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int tmp;
      scanf("%d", &tmp);
      sum_r[i] += tmp;
      sum_c[j] += tmp;
    }
  }
  for (int i = 0; i < n; i++) pqr.push(sum_r[i]);
  for (int i = 0; i < m; i++) pqc.push(sum_c[i]);
  cal(m, pqr, row);
  cal(n, pqc, col);
  long long ans = -INF;
  for (int i = 0; i <= k; i++) {
    long long tmp = row[i] + col[k - i] - i * 1LL * (k - i) * p;
    if (tmp > ans) ans = tmp;
  }
  printf("%I64d\n", ans);
  return 0;
}
