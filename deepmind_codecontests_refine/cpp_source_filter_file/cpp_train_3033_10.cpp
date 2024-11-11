#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int Mod = 1e9 + 7;
const int MaxN = 5e5 + 5;
const int MaxM = 1e6 + 5;
struct node {
  int x, id;
} f[25];
vector<node> q[MaxN];
int a[MaxN], ans[MaxN];
int main() {
  int n, m;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    q[r].push_back((node){l, i});
  }
  for (int i = 1; i <= n; i++) {
    node now = (node){a[i], i};
    for (int j = 20; j >= 0; j--) {
      if (now.x & (1 << j)) {
        if (!f[j].x) {
          f[j] = now;
          break;
        }
        if (f[j].id < i) swap(now, f[j]);
        now.x ^= f[j].x;
      }
    }
    for (int j = 0; j < q[i].size(); j++) {
      node now = q[i][j];
      for (int k = 20; k >= 0; k--) {
        if (f[k].id >= now.x)
          ans[now.id] = max(ans[now.id], ans[now.id] ^ f[k].x);
      }
    }
  }
  for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
  return 0;
}
