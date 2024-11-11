#include <bits/stdc++.h>
using namespace std;
int n, sum[1000010], dp[1000010];
char s[1000010];
vector<int> pos, ball;
inline int cnt(int l, int r) {
  if (l > r) return 0;
  return sum[r] - sum[l - 1];
}
bool check(int mid) {
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i < pos.size(); i++) {
    if (!cnt(dp[i - 1] + 1, pos[i] - mid - 1)) dp[i] = max(dp[i], pos[i]);
    if (!cnt(dp[i - 1] + 1, pos[i])) dp[i] = max(dp[i], pos[i] + mid);
    if (i != 1 && !cnt(dp[i - 2] + 1, pos[i] - mid - 1) &&
        pos[i] - mid < pos[i - 1])
      dp[i] = max(dp[i], pos[i - 1] + mid);
  }
  return !cnt(dp[pos.size() - 1] + 1, n);
}
int main() {
  scanf("%d%s", &n, s + 1);
  pos.push_back(0);
  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1];
    if (s[i] == '*')
      sum[i]++, ball.push_back(i);
    else if (s[i] == 'P')
      pos.push_back(i);
  }
  if (pos.size() == 2) {
    if (sum[pos[1]] > sum[n] - sum[pos[1]]) {
      printf("%d %d", sum[pos[1]], pos[1] - ball[0]);
    } else if (sum[pos[1]] == sum[n] - sum[pos[1]]) {
      if (sum[n] == 0)
        puts("0 0");
      else
        printf("%d %d", sum[pos[1]],
               min(pos[1] - ball[0], ball.back() - pos[1]));
    } else {
      printf("%d %d", sum[n] - sum[pos[1]], ball.back() - pos[1]);
    }
    return 0;
  }
  int L = 1, R = n, out = 0;
  while (L <= R) {
    int mid = (L + R) >> 1;
    if (check(mid))
      out = mid, R = mid - 1;
    else
      L = mid + 1;
  }
  printf("%d %d\n", ball.size(), out);
  return 0;
}
