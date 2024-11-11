#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
double t[200005], s[200005], a[200005], b[200005], dp[2][200005];
long long n, m;
double k(int m, int x, int y) {
  if (!(s[y] - s[x])) return 0;
  return double(dp[(m - 1) % 2][x] - dp[(m - 1) % 2][y] - a[x] + a[y] +
                s[x] * b[x] - s[y] * b[y]) /
         (s[x] - s[y]);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> t[i];
    s[i] = s[i - 1] + t[i];
    a[i] = a[i - 1] + s[i] / t[i];
    b[i] = b[i - 1] + 1 / t[i];
  }
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    dp[0][i] = 1e20;
  }
  for (int i = 1; i <= m; i++) {
    deque<int> q;
    q.push_back(0);
    for (int j = 1; j <= n; j++) {
      while (q.size() >= 2 && k(i, q[1], q[0]) <= b[j]) q.pop_front();
      dp[i % 2][j] = dp[(i - 1) % 2][q.front()] + a[j] - a[q.front()] +
                     s[q.front()] * b[q.front()] - s[q.front()] * b[j];
      while (q.size() >= 2 &&
             k(i, q[q.size() - 1], q[q.size() - 2]) >= k(i, j, q[q.size() - 1]))
        q.pop_back();
      q.push_back(j);
    }
  }
  cout << dp[m % 2][n] << endl;
  return 0;
}
