#include <bits/stdc++.h>
using namespace std;
int n, m;
int s[105];
char c[105];
int d[105], dp[1 << 21];
int calc(int val) {
  int ret = 0;
  while (val) {
    ret += (val & 1);
    val >>= 1;
  }
  return m - ret;
}
bool cmp(const int &a, const int &b) { return a > b; }
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> s[i];
  sort(s, s + n, cmp);
  cin >> m;
  for (int i = 0; i < m; i++) cin >> c[i] >> d[i];
  for (int i = 1; i < (1 << m); i++) {
    int cnt = calc(i);
    if (d[cnt] == 1)
      dp[i] = -(1 << 25);
    else
      dp[i] = (1 << 25);
    for (int j = 0; (1 << j) <= i; j++) {
      if (i & (1 << j)) {
        int val = 0;
        if (c[cnt] == 'p') val = s[j];
        if (d[cnt] == 1)
          dp[i] = max(dp[i], dp[i ^ (1 << j)] + val);
        else
          dp[i] = min(dp[i], dp[i ^ (1 << j)] - val);
      }
    }
  }
  cout << dp[(1 << m) - 1];
  return 0;
}
