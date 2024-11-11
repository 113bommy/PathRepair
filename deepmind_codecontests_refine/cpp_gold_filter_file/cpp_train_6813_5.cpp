#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
const int K = 1e6 + 5;
long long dat[N][N], n, m, k, p;
long long a[K], b[K];
priority_queue<long long> pqa, pqb;
int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  cin >> n >> m;
  cin >> k >> p;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cin >> dat[i][j];
  }
  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = 0; j < m; j++) sum += dat[i][j];
    pqa.push(sum);
  }
  for (int i = 1; i <= k; i++) {
    a[i] = pqa.top();
    pqa.pop();
    pqa.push(a[i] - m * p);
    a[i] += a[i - 1];
  }
  for (int j = 0; j < m; j++) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += dat[i][j];
    }
    pqb.push(sum);
  }
  for (int i = 1; i <= k; i++) {
    b[i] = pqb.top();
    pqb.pop();
    pqb.push(b[i] - n * p);
    b[i] += b[i - 1];
  }
  long long ans = -1e18;
  for (int i = 0; i <= k; i++) {
    ans = max(ans, a[i] + b[k - i] - (i * (k - i) * p));
  }
  cout << ans << "\n";
  return 0;
}
