#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:268435456,268435456")
using namespace std;
struct Node {
  int i, x;
  Node(int a, int b) : i(a), x(b) {}
};
int a[301], t[301], tt, dp[2][150001];
deque<Node> q1;
int main() {
  int n, m, d;
  long long b = 0;
  scanf("%d %d %d", &n, &m, &d);
  for (int i = 1; i <= m; i++) scanf("%d %d %d", &a[i], &tt, &t[i]), b += tt;
  for (int i = 1; i <= n; i++) dp[1][i] = abs(a[1] - i);
  for (int i = 2; i <= m; i++) {
    q1.clear();
    int len = min((long long)n, (long long)d * (t[i] - t[i - 1]));
    for (int j = 1; j <= len; j++) {
      while (!q1.empty() && dp[1 - (i & 1)][j] <= q1.back().x) q1.pop_back();
      q1.push_back(Node(j, dp[1 - (i & 1)][j]));
    }
    for (int j = 1; j + len <= n; j++) {
      while (!q1.empty() && dp[1 - (i & 1)][j + len] <= q1.back().x)
        q1.pop_back();
      q1.push_back(Node(j + len, dp[1 - (i & 1)][j + len]));
      while (!q1.empty() && abs(q1.front().i - j) > len) q1.pop_front();
      dp[i & 1][j] = q1.front().x + abs(a[i] - j);
    }
    for (int j = n - len + 1; j <= n; j++) {
      while (!q1.empty() && abs(q1.front().i - j) > len) q1.pop_front();
      dp[i & 1][j] = q1.front().x + abs(a[i] - j);
    }
  }
  printf("%I64d\n", b - *min_element(dp[m & 1] + 1, dp[m & 1] + 1 + n));
  return 0;
}
