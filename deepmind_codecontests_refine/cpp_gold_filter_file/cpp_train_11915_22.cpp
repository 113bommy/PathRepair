#include <bits/stdc++.h>
using namespace std;
int a[1010][1010], n, m, k, p;
priority_queue<long long> q, qu;
long long row[1000010], col[1000010];
long long ans;
int main() {
  scanf("%d%d%d%d", &n, &m, &k, &p);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) scanf("%d", &a[i][j]);
  long long ans = -(long long)1e18;
  for (int i = 0; i < n; i++) {
    long long tmp = 0;
    for (int j = 0; j < m; j++) tmp += a[i][j];
    q.push(tmp);
  }
  for (int i = 1; i <= k; i++) {
    long long tmp = q.top();
    q.pop();
    q.push(tmp - (long long)p * m);
    row[i] = row[i - 1] + tmp;
  }
  for (int i = 0; i < m; i++) {
    long long tmp = 0;
    for (int j = 0; j < n; j++) tmp += a[j][i];
    qu.push(tmp);
  }
  for (int i = 1; i <= k; i++) {
    long long tmp = qu.top();
    qu.pop();
    qu.push(tmp - (long long)p * n);
    col[i] = col[i - 1] + tmp;
  }
  for (int i = 0; i <= k; i++) {
    ans = max(ans, row[i] + col[k - i] - (long long)i * (k - i) * p);
  }
  printf("%I64d\n", ans);
  return 0;
}
