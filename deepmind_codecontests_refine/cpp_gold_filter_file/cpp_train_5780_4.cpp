#include <bits/stdc++.h>
using namespace std;
const int maxn = 100100;
set<int> st[maxn];
bool vis(int a, int b) { return st[a].find(b) != st[a].end(); }
void pute(int a, int b) {
  st[a].insert(b);
  st[b].insert(a);
}
struct edg {
  int w, sta, a;
  bool operator<(const edg &rhs) const {
    return w == rhs.w ? sta > rhs.sta : w < rhs.w;
  }
} ed[maxn];
int n, m, u[maxn], v[maxn];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &ed[i].w, &ed[i].sta);
    ed[i].a = i;
  }
  sort(ed + 1, ed + m + 1);
  int ca = 3, cb = 1, na = 2;
  bool flag = true;
  for (int i = 1; i <= m; ++i) {
    int p = ed[i].a;
    if (ed[i].sta == 0) {
      u[p] = ca;
      v[p] = cb++;
      if (ca >= na) {
        flag = false;
        break;
      }
      if (cb + 1 == ca) {
        ++ca;
        cb = 1;
      }
    } else {
      if (na > n) {
        flag = false;
        break;
      }
      u[p] = na - 1;
      v[p] = na++;
    }
  }
  if (!flag) {
    printf("-1\n");
  } else {
    for (int i = 1; i <= m; ++i) {
      printf("%d %d\n", u[i], v[i]);
    }
  }
  return 0;
}
