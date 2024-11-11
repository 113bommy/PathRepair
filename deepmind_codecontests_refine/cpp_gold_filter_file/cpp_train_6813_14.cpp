#include <bits/stdc++.h>
using namespace std;
priority_queue<long long> row, col;
long long a[2000005], b[2000005];
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  int n, m;
  long long k, p;
  cin >> n >> m >> k >> p;
  int mat[n + 1][m + 1];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> mat[i][j];
  for (int i = 1; i <= n; i++) {
    long long sum = 0;
    for (int j = 1; j <= m; j++) sum += mat[i][j];
    row.push(sum);
  }
  for (int i = 1; i <= m; i++) {
    long long sum = 0;
    for (int j = 1; j <= n; j++) {
      sum += mat[j][i];
    }
    col.push(sum);
  }
  for (int i = 1; i <= k; i++) {
    a[i] = row.top();
    row.pop();
    row.push(a[i] - p * m);
    a[i] += a[i - 1];
  }
  for (int i = 1; i <= k; i++) {
    b[i] = col.top();
    col.pop();
    col.push(b[i] - p * n);
    b[i] += b[i - 1];
  }
  long long ans = -(long long)999999999999999999;
  for (int i = 0; i <= k; i++) {
    ans = max(ans, a[i] + b[k - i] - 1LL * i * (k - i) * p);
  }
  cout << ans;
  return 0;
}
