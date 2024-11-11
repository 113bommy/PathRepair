#include <bits/stdc++.h>
using namespace std;
priority_queue<long long> col, row;
int n, m, k, p, a[1005][1005];
long long cc, cr, c[2][1000005], b, ans = -4e18;
int main() {
  scanf("%d %d %d %d", &n, &m, &k, &p);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) scanf("%d", &a[i][j]);
  for (int i = 0; i < n; i++) {
    b = 0;
    for (int j = 0; j < m; j++) b += a[i][j];
    row.push(b);
  }
  for (int i = 0; i < m; i++) {
    b = 0;
    for (int j = 0; j < n; j++) b += a[j][i];
    col.push(b);
  }
  for (int i = 1; i <= k; i++) {
    c[0][i] = c[0][i - 1] + col.top();
    b = col.top();
    col.pop();
    b -= p * n;
    col.push(b);
    c[1][i] = c[1][i - 1] + row.top();
    b = row.top();
    row.pop();
    b -= p * m;
    row.push(b);
  }
  for (int i = 0; i <= k; i++)
    ans = (ans > c[0][i] + c[1][k - i] - (long long)i * (k - i) * p
               ? ans
               : c[0][i] + c[1][k - i] - (long long)i * (k - i) * p);
  printf("%I64d\n", ans);
  scanf("\n");
  return 0;
}
