#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x) {
  T f = 1;
  x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = x * 10 + s - '0';
    s = getchar();
  }
  x *= f;
}
template <typename T>
void prll(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) prll(x / 10);
  putchar(x % 10 + '0');
}
struct Change {
  int x, y, Ans;
} q[2005];
char s[2005][2005];
int up[2005][2005], down[2005][2005];
int dp[2005][2005];
int n, m, Q;
struct Deque {
  int s, t, deq[2005];
  Deque() { s = 1, t = 0; }
  bool empty() { return s > t; }
  void push_back(int x) { deq[++t] = x; }
  void pop_back() { t--; }
  void pop_front() { s++; }
  void clear() { s = 1, t = 0; }
  int front() { return deq[s]; }
  int back() { return deq[t]; }
} q1, q2;
bool check(const int x, const int len) {
  q1.clear();
  q2.clear();
  for (int i = 1; i < len; i++) {
    while (!q1.empty() && up[x][q1.back()] >= up[x][i]) q1.pop_back();
    q1.push_back(i);
    while (!q2.empty() && down[x][q2.back()] >= down[x][i]) q2.pop_back();
    q2.push_back(i);
  }
  for (int i = len; i <= m; i++) {
    while (!q1.empty() && q1.front() <= i - len) q1.pop_front();
    while (!q2.empty() && q2.front() <= i - len) q2.pop_front();
    while (!q1.empty() && up[x][q1.back()] >= up[x][i]) q1.pop_back();
    q1.push_back(i);
    while (!q2.empty() && down[x][q2.back()] >= down[x][i]) q2.pop_back();
    q2.push_back(i);
    if (up[x][q1.front()] + down[x][q2.front()] - 1 >= len) return true;
  }
  return false;
}
int main() {
  read(n);
  read(m);
  read(Q);
  for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
  for (int i = 1; i <= Q; i++) {
    read(q[i].x);
    read(q[i].y);
    s[q[i].x][q[i].y] = 'X';
    q[i].Ans = 0;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i][j] != '.') s[i][j] = 0;
      if (s[i][j]) up[i][j] = up[i - 1][j] + 1;
    }
  }
  for (int i = n; i >= 1; i--) {
    for (int j = 1; j <= m; j++)
      if (s[i][j]) down[i][j] = down[i + 1][j] + 1;
  }
  int res = 0;
  for (int i = 1; i <= n; i++)
    if (s[i][1]) dp[i][1] = 1, res = max(res, dp[i][1]);
  for (int i = 1; i <= m; i++)
    if (s[1][i]) dp[1][i] = 1, res = max(res, dp[i][1]);
  for (int i = 2; i <= n; i++) {
    for (int j = 2; j <= m; j++)
      if (s[i][j])
        dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1,
        res = max(res, dp[i][j]);
  }
  for (int i = Q; i >= 1; i--) {
    q[i].Ans = res;
    if (i == 1) break;
    int x = q[i].x, y = q[i].y;
    s[x][y] = 1;
    for (int i = 1; i <= n; i++)
      if (s[i][y]) up[i][y] = up[i - 1][y] + 1;
    for (int i = n; i >= 1; i--)
      if (s[i][y]) down[i][y] = down[i + 1][y] + 1;
    int l = 0, r = m, mid, ans;
    while (l <= r) {
      mid = (l + r) >> 1;
      if (check(x, mid))
        l = mid + 1, ans = mid;
      else
        r = mid - 1;
    }
    res = max(ans, res);
  }
  for (int i = 1; i <= Q; i++) printf("%d\n", q[i].Ans);
  return 0;
}
