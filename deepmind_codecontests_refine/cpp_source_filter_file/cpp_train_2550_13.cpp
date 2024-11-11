#include <bits/stdc++.h>
using namespace std;
const int P = 1000000007;
const int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
const int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
char vis[3010][3010];
long long ans[505];
void bfs(int k) {
  queue<int> qx;
  queue<int> qy;
  queue<int> qstep;
  qx.push(1505);
  qy.push(1505);
  qstep.push(0);
  vis[1505][1505] = 1;
  while (!qx.empty()) {
    int x = qx.front(), y = qy.front(), s = qstep.front();
    qx.pop();
    qy.pop();
    qstep.pop();
    ++ans[s];
    if (s == k) continue;
    for (int i = 0; i < 8; ++i) {
      if (vis[x + dx[i]][y + dy[i]]) continue;
      vis[x + dx[i]][y + dy[i]] = 1;
      qx.push(x + dx[i]);
      qy.push(y + dy[i]);
      qstep.push(s + 1);
    }
  }
}
int main() {
  long long k;
  int n;
  scanf("%11d%d", &k, &n);
  for (int i = 1; i < n; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    vis[x + 1505][y + 1505] = 1;
  }
  bfs(500);
  if (k <= 500) {
    int res = 0;
    for (int i = 0; i < k; ++i) res += ans[i];
    printf("%d", res);
    return 0;
  }
  long long inc = ans[500] - ans[499];
  k -= 499;
  k %= P;
  long long cnt = 0;
  for (int i = 0; i <= 499; ++i) cnt = (cnt + ans[i]) % P;
  cnt = (cnt + ans[500] * k % P + (k * (k - 1) >> 1) % P * inc) % P;
  printf("%11d", cnt);
}
