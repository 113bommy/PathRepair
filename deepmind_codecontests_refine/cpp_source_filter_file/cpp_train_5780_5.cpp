#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const int maxm = 500 * 500 + 10;
const int inf = 1e9;
const long long mod = 1e9 + 7;
int getint() {
  char c;
  while ((c = getchar()) && !(c >= '0' && c <= '9') && c != '-')
    ;
  int ret = c - '0', sgn = 0;
  if (c == '-') sgn = 1, ret = 0;
  while ((c = getchar()) && c >= '0' && c <= '9') ret = ret * 10 + c - '0';
  if (sgn) ret = -ret;
  return ret;
}
struct node {
  int id, k, w;
  bool operator<(const node a) const {
    if (w != a.w)
      return w < a.w;
    else
      return k > a.k;
  }
} p[maxn];
pair<int, int> ans[maxn];
int vis[maxn];
int main() {
  int n = getint(), m = getint();
  for (int i = 1; i <= m; i++) {
    p[i].w = getint(), p[i].k = getint(), p[i].id = i;
  }
  sort(p + 1, p + m + 1);
  int flag = 1;
  int tot = 1;
  int l = 2, r = 3;
  memset(vis, 0, sizeof(vis));
  for (int i = 1; i <= m; i++) {
    if (p[i].k == 0) {
      int f = 1;
      if (l == r) r++, l = 2;
      if (l < r && r <= tot) ans[p[i].id] = make_pair(l, r), f = 0, l++;
      if (f) {
        flag = 1;
        break;
      }
    } else {
      ans[p[i].id] = make_pair(1, ++tot);
    }
  }
  if (flag) {
    for (int i = 1, j = 0; i <= m; i++) {
      cout << ans[i].first << " " << ans[i].second << endl;
    }
  } else
    puts("-1");
  return 0;
}
