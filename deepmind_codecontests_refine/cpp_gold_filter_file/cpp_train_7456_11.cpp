#include <bits/stdc++.h>
using namespace std;
int getint() {
  int ans = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    ans = ans * 10 + c - '0';
    c = getchar();
  }
  return ans * f;
}
const int N = 1e6 + 10;
char s[N];
vector<int> d, b;
int n, sum[N], dp[N];
bool empty(int l, int r) { return (r < l) || (sum[r] - sum[l - 1] == 0); }
bool check(int mid) {
  memset(dp, 0, sizeof(int) * (n + 2));
  for (int i = 0; i < d.size(); i++) {
    if (empty(dp[i] + 1, d[i] - mid - 1)) dp[i + 1] = max(dp[i + 1], d[i]);
    if (empty(dp[i] + 1, d[i] - 1)) dp[i + 1] = max(dp[i + 1], d[i] + mid);
    if (i && empty(dp[i - 1] + 1, d[i] - mid - 1) && d[i] - mid < d[i - 1])
      dp[i + 1] = max(dp[i + 1], d[i - 1] + mid);
  }
  return empty(dp[d.size()] + 1, n);
}
int main() {
  n = getint();
  scanf("%s", s + 1);
  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1];
    if (s[i] == 'P') d.push_back(i);
    if (s[i] == '*') b.push_back(i), sum[i] = sum[i - 1] + 1;
  }
  if (d.size() == 1) {
    int cntl = 0, cntr = 0;
    for (auto i : b) (i < d[0] ? cntl : cntr)++;
    if (cntl > cntr)
      cout << cntl << " " << d[0] - b[0] << endl;
    else
      cout << cntr << " " << b[b.size() - 1] - d[0] << endl;
    return 0;
  }
  int l = 0, r = n, mid, ans = 233;
  while (l <= r) {
    mid = l + r >> 1;
    if (check(mid))
      ans = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  cout << b.size() << " " << ans << endl;
}
