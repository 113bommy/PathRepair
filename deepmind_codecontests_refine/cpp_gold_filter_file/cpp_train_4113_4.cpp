#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 7;
const int M = 1e6 + 7;
const int lim = 2e6;
const int p = 998244353;
const int inf = 0x3f3f3f3f;
struct Node {
  int a, x, y;
} sz[N];
int vis[807], num[807];
bool cmp(Node s, Node t) { return s.a > t.a; }
int main() {
  int n, cnt = 0, m;
  scanf("%d", &n);
  for (int i = 2; i <= 2 * n; i++) {
    for (int j = 1; j < i; j++) {
      scanf("%d", &sz[++cnt].a);
      sz[cnt].x = i;
      sz[cnt].y = j;
    }
  }
  for (int i = 1; i <= 2 * n; i++) vis[i] = 1;
  sort(sz + 1, sz + 1 + cnt, cmp);
  for (int i = 1; i <= cnt; i++) {
    if (vis[sz[i].x] == 1 && vis[sz[i].y] == 1) {
      num[sz[i].x] = sz[i].y;
      num[sz[i].y] = sz[i].x;
      vis[sz[i].x] = 0;
      vis[sz[i].y] = 0;
    }
  }
  for (int i = 1; i <= 2 * n; i++)
    printf("%d%c", num[i], i == 2 * n ? '\n' : ' ');
  return 0;
}
