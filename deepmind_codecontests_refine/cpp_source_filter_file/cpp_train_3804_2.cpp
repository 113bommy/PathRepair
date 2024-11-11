#include <bits/stdc++.h>
using namespace std;
const int maxn = 1001100;
const int lim = 1e9 + 5;
map<int, int> bit[maxn];
map<int, int> vis;
int tot = 0;
int lowbit(int x) { return x & (-x); }
int sum(int nx, int ny) {
  int s = 0;
  while (ny > 0) {
    s += bit[nx][ny];
    ny -= lowbit(ny);
  }
  return s;
}
void add(int nx, int ny, int lx) {
  while (ny <= lim) {
    bit[nx][ny] += lx;
    ny += lowbit(ny);
  }
}
int main() {
  int n;
  int x, y, z;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d%d", &x, &y, &z);
    if (!vis[z]) vis[z] = ++tot;
    if (x == 1)
      add(vis[z], y, 1);
    else if (x == 2)
      add(vis[z], y, -1);
    else
      printf("%d\n", sum(vis[z], x));
  }
  return 0;
}
