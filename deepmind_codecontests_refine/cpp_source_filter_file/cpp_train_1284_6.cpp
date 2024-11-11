#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long linf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 20 + 10;
int n, k, t;
int cnt, sum, mid;
struct node {
  int x, y, z;
} a[maxn * maxn];
bool vis[maxn];
void dfs(int d) {
  if (cnt > t) return;
  if (d >= k) {
    cnt++;
    return;
  }
  dfs(d + 1);
  if (!vis[a[d].x] && !vis[a[d].y]) {
    sum += a[d].z;
    if (sum > mid) {
      sum -= a[d].z;
      return;
    }
    vis[a[d].x] = 1;
    vis[a[d].y] = 1;
    dfs(d + 1);
    sum -= a[d].z;
    vis[a[d].x] = 0;
    vis[a[d].y] = 0;
  }
}
int main() {
  scanf("%d", &n);
  scanf("%d", &k);
  scanf("%d", &t);
  memset(vis, 0, sizeof vis);
  for (int i = 0; i < k; i++) {
    int x, y, z;
    scanf("%d", &a[i].x);
    scanf("%d", &a[i].y);
    a[i].y += maxn;
    scanf("%d", &a[i].z);
  }
  int l = -1, r = inf;
  mid = 10;
  dfs(0);
  while (l < r - 1) {
    cnt = sum = 0;
    mid = l + r >> 1;
    dfs(0);
    if (cnt >= t) {
      r = mid;
    } else {
      l = mid;
    }
  }
  printf("%d\n", r);
}
