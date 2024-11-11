#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
  return x * f;
}
const int dx[] = {2, 2, 1, 1, -2, -2, -1, -1};
const int dy[] = {1, -1, 2, -2, 1, -1, 2, -2};
bool vis[5000][5000];
struct Point {
  Point(){};
  Point(int X, int Y, int T) { x = X, y = Y, t = T; }
  int x, y, t;
};
queue<Point> q;
int n;
long long k, ans[505];
const long long P = 967247387;
int main() {
  k = read(), n = read();
  for (int i = 1; i <= n; i++) {
    int x = read(), y = read();
    bool tmp = x == 0 && y == 0;
    assert(!tmp);
    vis[x + 2000][y + 2000] = 1;
  }
  q.push(Point(2000, 2000, 0));
  ans[0] = 1;
  vis[2000][2000] = 1;
  while (!q.empty() && q.front().t < min(k, (long long)500)) {
    Point now = q.front();
    q.pop();
    for (int i = 0; i < 8; i++) {
      int tx = now.x + dx[i], ty = now.y + dy[i];
      if (!vis[tx][ty]) {
        ans[now.t + 1]++;
        vis[tx][ty] = 1;
        q.push(Point(tx, ty, now.t + 1));
      }
    }
  }
  long long Ans = 0;
  if (k <= 500)
    for (int i = 0; i <= k; i++) Ans += ans[i];
  else {
    long long d = ans[500] - ans[499];
    for (int i = 0; i < 500; i++) Ans += ans[i];
    k -= 499;
    k %= P;
    Ans = (Ans + ans[500] * k + (k - 1) * k / 2 % P * d) % P;
  }
  printf("%lld", Ans);
}
