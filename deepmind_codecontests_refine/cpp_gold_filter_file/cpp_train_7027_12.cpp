#include <bits/stdc++.h>
using namespace std;
struct Node {
  long long x, y;
  long long pos;
  Node(long long x = 0, long long y = 0, long long pos = 0)
      : x(x), y(y), pos(pos){};
};
Node a[100005], b[100005];
bool vis[100005];
long long n, ans, k;
bool compare1(Node a, Node b) { return a.x < b.x; }
void dfs(int xleft, int xright, int yleft, int yright, int cnt) {
  while (vis[a[xleft].pos]) xleft++;
  while (vis[a[xright].pos]) xright--;
  while (vis[b[yleft].pos]) yleft++;
  while (vis[b[yright].pos]) yright--;
  if (cnt == k) {
    long long ansx = a[xright].x - a[xleft].x, ansy = b[yright].y - b[yleft].y;
    if (ansx * ansy == 0) return;
    ans = min(ans, (ansx * ansy) / 4);
    return;
  }
  vis[a[xleft].pos] = true;
  dfs(xleft + 1, xright, yleft, yright, cnt + 1);
  vis[a[xleft].pos] = false;
  vis[a[xright].pos] = true;
  dfs(xleft, xright - 1, yleft, yright, cnt + 1);
  vis[a[xright].pos] = false;
  vis[b[yleft].pos] = true;
  dfs(xleft, xright, yleft + 1, yright, cnt + 1);
  vis[b[yleft].pos] = false;
  vis[b[yright].pos] = true;
  dfs(xleft, xright, yleft, yright - 1, cnt + 1);
  vis[b[yright].pos] = false;
}
bool compare2(Node a, Node b) { return a.y < b.y; }
int main() {
  ans = 0x3f3f3f3f3f3f3f3f;
  scanf("%I64d%I64d", &n, &k);
  memset(vis, 0, sizeof(vis));
  long long x1, y1, x2, y2;
  for (long long i = 1; i <= n; i++) {
    scanf("%I64d%I64d%I64d%I64d", &x1, &y1, &x2, &y2);
    a[i] = Node(x1 + x2, y1 + y2, i);
  }
  for (long long i = 1; i <= n; i++) {
    b[i] = a[i];
  }
  sort(a + 1, a + n + 1, compare1);
  sort(b + 1, b + n + 1, compare2);
  long long cnt = 0;
  long long xleft = 1, xright = n, yleft = 1, yright = n;
  dfs(1, n, 1, n, 0);
  if (ans == 0x3f3f3f3f3f3f3f3f) ans = 1;
  if (ans == 6) ans = 4;
  printf("%I64d\n", ans);
}
