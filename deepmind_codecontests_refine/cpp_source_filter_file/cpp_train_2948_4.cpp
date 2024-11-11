#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
void qread(int &x) {
  int neg = 1;
  x = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') neg = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') x = 10 * x + c - '0', c = getchar();
  x *= neg;
}
const int maxn = 100005;
int n, l, r, k, ans, ansu, ansv;
vector<pair<int, int> > edge[maxn];
vector<int> num;
int oriw[maxn], w[maxn], dep[maxn], lvl[maxn], son[maxn];
int pos[maxn], dis[maxn];
pair<int, int> val[maxn];
namespace Segtree {
int sz;
pair<int, int> t[maxn * 4];
void init(int _sz) {
  for (sz = 1; sz < _sz; sz <<= 1)
    ;
  for (int(i) = 0; (i) < sz << 1; i++) t[i] = make_pair(-1e9, -1e9);
}
void update(int v, pair<int, int> val) {
  v += sz - 1;
  t[v] = val;
  for (v >>= 1; v; v >>= 1) t[v] = max(t[v << 1], t[v << 1 | 1]);
}
pair<int, int> query(int l, int r) {
  pair<int, int> res = make_pair(-1e9, -1e9);
  for (l += sz - 1, r += sz - 1; l <= r; l >>= 1, r >>= 1) {
    if (l & 1) res = max(res, t[l]), l++;
    if ((r + 1) & 1) res = max(res, t[r]), r--;
  }
  return res;
}
}  // namespace Segtree
void prework1(int x, int p, int d) {
  dep[x] = lvl[x] = d;
  for (int(i) = 0; (i) < edge[x].size(); i++) {
    pair<int, int> y = edge[x][i];
    if (y.first == p) continue;
    prework1(y.first, x, d + 1);
    if (!son[x] || lvl[y.first] > lvl[son[x]]) son[x] = y.first;
    lvl[x] = max(lvl[x], lvl[y.first]);
  }
}
void prework2(int x, int p) {
  pos[x] = ++k;
  if (son[x]) prework2(son[x], x);
  for (int(i) = 0; (i) < edge[x].size(); i++) {
    pair<int, int> y = edge[x][i];
    if (y.first == p || y.first == son[x]) continue;
    prework2(y.first, x);
  }
}
void work(int x, int p, int cur) {
  val[pos[x]] = make_pair(cur, x);
  dis[x] = cur;
  Segtree::update(pos[x], make_pair(cur, x));
  for (int(i) = 0; (i) < edge[x].size(); i++) {
    int y = edge[x][i].first;
    if (y == son[x]) work(y, x, cur + w[edge[x][i].second]);
  }
  for (int(i) = 0; (i) < edge[x].size(); i++) {
    int y = edge[x][i].first;
    if (y == p || y == son[x]) continue;
    work(y, x, cur + w[edge[x][i].second]);
    int tmp = lvl[y] - dep[y];
    for (int(d) = 0; (d) < tmp + 1; d++) {
      int ql = max(l - d - 1, 0), qr = min(r - d - 1, lvl[x] - dep[x]);
      pair<int, int> val2 = Segtree::query(pos[x] + ql, pos[x] + qr);
      if (val[pos[y] + d].first + val2.first - 2 * dis[x] > ans) {
        ans = val[pos[y] + d].first + val2.first - 2 * dis[x];
        ansu = val[pos[y] + d].second;
        ansv = val2.second;
      }
    }
    for (int(d) = 0; (d) < tmp + 1; d++) {
      val[pos[x] + d + 1] = max(val[pos[x] + d + 1], val[pos[y] + d]);
      Segtree::update(pos[x] + d + 1, val[pos[x] + d + 1]);
    }
  }
  pair<int, int> val2 =
      Segtree::query(pos[x] + l, pos[x] + min(r, lvl[x] - dep[x]));
  if (val2.first - dis[x] > ans) {
    ans = val2.first - dis[x];
    ansu = x;
    ansv = val2.second;
  }
}
bool check(int x) {
  for (int(i) = 1; (i) <= n - 1; i++) {
    if (oriw[i] < x)
      w[i] = -1;
    else
      w[i] = 1;
  }
  Segtree::init(n);
  for (int(i) = 1; (i) <= n; i++) val[i] = make_pair(-1e9, -1e9);
  ans = -1e9;
  work(1, 0, 0);
  return ans > 0;
}
int main() {
  scanf("%d%d%d", &n, &l, &r);
  for (int(i) = 1; (i) <= n - 1; i++) {
    int u, v;
    scanf("%d%d%d", &u, &v, &oriw[i]);
    edge[u].push_back(make_pair(v, i));
    edge[v].push_back(make_pair(u, i));
    num.push_back(oriw[i]);
  }
  prework1(1, 0, 0);
  prework2(1, 0);
  sort(num.begin(), num.end());
  num.resize(unique(num.begin(), num.end()) - num.begin());
  int l = 0, r = num.size();
  while (r - l > 1) {
    int mid = (l + r) >> 1;
    if (check(num[mid]))
      l = mid;
    else
      r = mid;
  }
  check(num[l]);
  printf("%d %d\n", ansu, ansv);
  return 0;
}
