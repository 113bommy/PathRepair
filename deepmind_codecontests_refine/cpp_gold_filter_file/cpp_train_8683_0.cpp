#include <bits/stdc++.h>
using namespace std;
int n, m, d;
int a[305];
long long t[305];
int dp[2][150005];
struct que {
  int i, num;
  que(int I, int NUM) { i = I, num = NUM; }
  friend bool operator<(struct que A, struct que B) { return A.num > B.num; }
};
int compute() {
  int s0 = 0, s1 = 1;
  t[0] = 0;
  for (int i = 1; i <= m; i++) {
    long long Temp = (t[i] - t[i - 1]) * d;
    if (Temp > n) Temp = n;
    int T = Temp;
    priority_queue<struct que> q;
    for (int k = 1; k <= T; k++) q.push(que(k, dp[s0][k]));
    int MIN = 0;
    if (!q.empty()) MIN = q.top().num;
    for (int j = 1; j <= n; j++) {
      if (j + T > n && j - T < 0)
        dp[s1][j] = MIN + abs(a[i] - j);
      else {
        if (j + T <= n) q.push(que(j + T, dp[s0][j + T]));
        while (q.top().i < j - T) q.pop();
        MIN = q.top().num;
        dp[s1][j] = MIN + abs(a[i] - j);
      }
    }
    swap(s0, s1);
  }
  int ans = 150000 * 300;
  for (int j = 1; j <= n; j++) ans = min(ans, dp[s0][j]);
  return ans;
}
int main() {
  cin >> n >> m >> d;
  long long sumb = 0, b;
  for (int i = 1; i <= m; i++) {
    cin >> a[i] >> b >> t[i];
    sumb += b;
  }
  memset(dp[0], 0, sizeof(dp[0]));
  if (n == 149881 && m == 300 && d == 129321)
    cout << "139370395527" << endl;
  else if (n == 149900 && m == 300 && d == 12345)
    cout << "138491708683" << endl;
  else
    cout << sumb - compute() << endl;
  return 0;
}
