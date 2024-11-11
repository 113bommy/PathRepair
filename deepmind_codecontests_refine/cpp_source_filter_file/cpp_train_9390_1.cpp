#include <bits/stdc++.h>
using namespace std;
const int MAXN = (int)1e5 + 10;
int n, m, k;
int fa[MAXN];
int visit[MAXN];
vector<int> res;
struct node {
  int x, y, id;
  double w;
  node() {}
  node(int x_, int y_, double w_, int id_) {
    x = x_;
    y = y_;
    w = w_;
    id = id_;
  }
  friend bool operator<(const node &a, const node &b) { return a.w < b.w; }
};
vector<node> e1, e2;
int getfa(int x) {
  if (fa[x] == x) return x;
  return fa[x] = getfa(fa[x]);
}
int get_ans(double mid, int K = -1) {
  static node e[MAXN];
  for (int i = 0; i < e1.size(); i++) e1[i].w += mid;
  for (int i = 1; i <= n; i++) fa[i] = i;
  int cnt = 0, tot = 0;
  int p1 = 0, p2 = 0;
  while (p1 != e1.size() && p2 != e2.size()) {
    if (p1 == e1.size())
      e[tot++] = e2[p2++];
    else if (p2 == e2.size())
      e[tot++] = e1[p1++];
    else {
      if (e1[p1].w == e2[p2].w) {
        if (mid > 0)
          e[tot++] = e1[p1++];
        else
          e[tot++] = e2[p2++];
      } else if (e1[p1].w > e2[p2].w)
        e[tot++] = e2[p2++];
      else
        e[tot++] = e1[p1++];
    }
  }
  res.clear();
  for (int i = 0; i < m; i++) {
    if ((e[i].x == 1 || e[i].y == 1) && cnt == K) continue;
    int x = getfa(e[i].x), y = getfa(e[i].y);
    if (x != y) {
      res.push_back(e[i].id);
      if (e[i].x == 1 || e[i].y == 1) ++cnt;
      fa[x] = y;
    }
  }
  for (int i = 0; i < e1.size(); i++) e1[i].w -= mid;
  return cnt;
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++) fa[i] = i;
  int las = n;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    if (u == 1 || v == 1)
      e1.push_back(node(u, v, (double)w, i + 1));
    else
      e2.push_back(node(u, v, (double)w, i + 1));
    if (getfa(u) != getfa(v)) {
      fa[getfa(u)] = getfa(v);
      las--;
    }
  }
  if (e1.size() < k || (las != 1)) {
    printf("-1\n");
    return 0;
  }
  sort(e1.begin(), e1.end());
  sort(e2.begin(), e2.end());
  double l = -1e6, r = 1e6, ans = -1;
  if (get_ans(l) < k || get_ans(r) > k) {
    printf("-1\n");
    return 0;
  }
  for (int i = 1; i < 50; i++) {
    int mid = (l + r) / 2.0;
    if (get_ans(mid) >= k) {
      ans = mid;
      l = mid;
    } else
      r = mid;
  }
  get_ans(ans, k);
  cout << res.size() << endl;
  for (int i = 0; i < res.size(); i++) printf("%d ", res[i]);
  printf("\n");
  return 0;
}
