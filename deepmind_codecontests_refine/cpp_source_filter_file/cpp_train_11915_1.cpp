#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int mod = 1e9 + 7;
int a[1010][1010];
long long s[1010][1010];
long long d[1010][1010];
long long ans1[1010];
long long ans2[1010];
long long n, m, k, p;
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m >> k >> p;
  int i, j;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      cin >> a[i][j];
      s[i][j] = s[i][j - 1] + a[i][j];
    }
  }
  for (int i = 1; i <= m; i++) {
    for (j = 1; j <= n; j++) {
      d[j][i] = d[j - 1][i] + a[j][i];
    }
  }
  priority_queue<long long> q1;
  priority_queue<long long> q2;
  for (i = 1; i <= n; i++) {
    q1.push(s[i][m]);
  }
  for (i = 1; i <= m; i++) {
    q2.push(d[n][i]);
  }
  for (i = 1; i <= k; i++) {
    auto x = q1.top();
    q1.pop();
    ans1[i] = ans1[i - 1] + x;
    x -= (long long)m * p;
    q1.push(x);
  }
  for (i = 1; i <= k; i++) {
    auto x = q2.top();
    q2.pop();
    ans2[i] = ans2[i - 1] + x;
    x -= (long long)n * p;
    q2.push(x);
  }
  long long res = -1e18;
  for (i = 0; i <= k; i++) {
    res = max(res, ans1[i] + ans2[k - i] - 1ll * i * (k - i) * p);
  }
  cout << res << endl;
  return 0;
}
