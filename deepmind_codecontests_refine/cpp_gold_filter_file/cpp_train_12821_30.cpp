#include <bits/stdc++.h>
const long long inf = (long long)(1e18 + 7);
using namespace std;
int n, a[500010], b[500010];
int c[500010], d[500010];
int ra[500010], rb[500010];
int rc[500010], rd[500010];
struct D {
  int x, y, p, q;
  D(int _x, int _y, int _p, int _q) : x(_x), y(_y), p(_p), q(_q) {}
};
vector<D> ans;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    ra[a[i]] = i;
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &b[i]);
    rb[b[i]] = i;
  }
  for (int i = 1; i <= n; ++i) c[i] = d[i] = rc[i] = rd[i] = i;
  for (int i = 1; i <= n; ++i) {
    if (c[i] == ra[i] && d[i] == rb[i]) continue;
    ans.emplace_back(i, rd[rb[i]], rc[ra[i]], i);
    int t1 = c[i];
    int t2 = d[i];
    swap(c[i], c[rc[ra[i]]]);
    swap(d[i], d[rd[rb[i]]]);
    swap(rc[ra[i]], rc[t1]);
    swap(rd[rb[i]], rd[t2]);
  }
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); ++i)
    printf("%d %d %d %d\n", ans[i].x, ans[i].y, ans[i].p, ans[i].q);
  return 0;
}
