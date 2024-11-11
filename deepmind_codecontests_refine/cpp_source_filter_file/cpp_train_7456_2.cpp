#include <bits/stdc++.h>
const int MAXN = 1e6 + 5;
using namespace std;
int n, a[MAXN], num, d[MAXN], b[MAXN];
int p[MAXN], dp[MAXN];
string s;
bool check(int k) {
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= d[n]; i++) {
    if (dp[i - 1] >= p[i] - 1 || b[dp[i - 1]] == b[p[i] - 1])
      dp[i] = max(dp[i], p[i] + k);
    if (dp[i - 1] >= p[i] - k - 1 || b[dp[i - 1]] == b[p[i] - k - 1])
      dp[i] = max(dp[i], p[i]);
    if (i > 1 && (dp[i - 2] >= p[i] - k + 1 || b[dp[i - 2]] == b[p[i] - k - 1]))
      dp[i] = max(dp[i], p[i - 1] + k);
    dp[i] = min(dp[i], n);
  }
  if (dp[d[n]] == n)
    return 1;
  else
    return 0;
}
int main() {
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == '.')
      a[i + 1] = 0;
    else if (s[i] == '*')
      a[i + 1] = 1;
    else {
      a[i + 1] = 2;
      num++;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] == 2) {
      d[i] = d[i - 1] + 1;
      p[d[i]] = i;
    } else
      d[i] = d[i - 1];
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] == 1)
      b[i] = b[i - 1] + 1;
    else
      b[i] = b[i - 1];
  }
  if (num == 1) {
    int f = 0, num1 = 0, num2 = 0, t1 = n, t2 = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] == 2)
        f = i;
      else if (a[i] == 1) {
        if (f == 0) {
          num1++;
          t1 = min(t1, i);
        } else {
          num2++;
          t2 = max(t2, i);
        }
      }
    }
    if (num1 > num2)
      cout << num1 << " " << f - t1 << endl;
    else if (num1 < num2)
      cout << num2 << " " << t2 - f << endl;
    else
      cout << num1 << " " << min(f - t1, t2 - f) << endl;
    return 0;
  }
  int l = 1, r = n, ans = n;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid)) {
      r = mid - 1;
      ans = mid;
    } else
      l = mid + 1;
  }
  cout << b[n] << " " << ans << endl;
  return 0;
}
