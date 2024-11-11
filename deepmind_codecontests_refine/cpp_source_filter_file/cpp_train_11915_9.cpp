#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const int M = 1e3 + 5;
const long long INF = 1e18;
priority_queue<long long> row, col;
long long r[N], c[N];
int a[M][M];
int main() {
  int n, m, k, p;
  cin >> n >> m >> k >> p;
  for (int i = 0; i < n; i++) {
    long long sum = 0;
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      sum += a[i][j];
    }
    row.push(sum);
  }
  for (int j = 0; j < m; j++) {
    long long sum = 0;
    for (int i = 0; i < n; i++) sum += a[i][j];
    col.push(sum);
  }
  for (int i = 1; i <= k; i++) {
    long long temp = row.top();
    row.pop();
    r[i] = r[i - 1] + temp;
    row.push(temp - m * p);
  }
  for (int i = 1; i <= k; i++) {
    long long temp = col.top();
    col.pop();
    c[i] = c[i - 1] + temp;
    col.push(temp - n * p);
  }
  long long ans = -INF;
  for (int i = 1; i <= k; i++) {
    ans = max(ans, r[i] + c[k - i] - 1ll * i * (k - i) * p);
  }
  cout << ans << endl;
  return 0;
}
