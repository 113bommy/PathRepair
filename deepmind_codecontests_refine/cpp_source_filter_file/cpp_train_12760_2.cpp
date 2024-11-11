#include <bits/stdc++.h>
using namespace std;
struct st {
  long long x, y, smer, raz;
};
bool used[666][666][8][32];
bool mark[666][666];
long long d[44];
long long sy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
long long sx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
queue<st> q;
int main() {
  long long n, ans = 0;
  scanf("%lld", &n);
  for (long long i = 0; i < n; i++) {
    scanf("%lld", d + i);
  }
  q.push({333, 333, 0, 0});
  while (!q.empty()) {
    long long x = q.front().x;
    long long y = q.front().y;
    long long t = q.front().smer;
    long long od = q.front().raz;
    q.pop();
    if (od == n) continue;
    if (used[x][y][t][od]) continue;
    used[x][y][t][od] = 1;
    for (long long i = 0; i < d[od]; i++) {
      x += sx[t];
      y += sy[t];
      mark[x][y] = 1;
    }
    q.push({x, y, (t + 1) % 8, od + 1});
    q.push({x, y, (t - 1 + 8) % 8, od + 1});
  }
  for (long long i = 0; i < 444; i++)
    for (long long j = 0; j < 444; j++)
      if (mark[i][j]) ans++;
  printf("%lld\n", ans);
  return 0;
}
