#include <bits/stdc++.h>
using namespace std;
const int inf = ~0U >> 1;
const long long INF = ~0ULL >> 1;
template <class T>
inline void read(T &n) {
  char c;
  for (c = getchar(); !(c >= '0' && c <= '9'); c = getchar())
    ;
  n = c - '0';
  for (c = getchar(); c >= '0' && c <= '9'; c = getchar()) n = n * 10 + c - '0';
}
int Pow(int base, int n, int mo) {
  if (n == 0) return 1;
  if (n == 1) return base % mo;
  int tmp = Pow(base, n >> 1, mo);
  tmp = (long long)tmp * tmp % mo;
  if (n & 1) tmp = (long long)tmp * base % mo;
  return tmp;
}
const int maxl = 200100;
const int maxn = 120000;
int h[maxn], f[maxn];
int n, m, ty, p;
set<int> trees;
map<int, int> b;
pair<int, int> buff[maxn];
int buf[maxn];
priority_queue<pair<int, int> > tmp;
struct seg_tree {
  struct Node {
    int l, r;
    int m;
  } t[maxl * 5];
  void modify(int p, int target, int newf) {
    if (t[p].l == t[p].r) {
      t[p].m = newf;
      return;
    }
    int m = t[p].l + t[p].r >> 1;
    if (target <= m)
      modify(p << 1, target, newf);
    else
      modify((p << 1) + 1, target, newf);
    t[p].m = max(t[p << 1].m, t[(p << 1) + 1].m);
  }
  void build(int p, int l, int r) {
    t[p].l = l;
    t[p].r = r;
    if (l != r) {
      build(p << 1, l, l + r >> 1);
      build((p << 1) + 1, (l + r >> 1) + 1, r);
    }
  }
  int query(int p, int l, int r) {
    if (l > r) return 0;
    if (t[p].l == l && t[p].r == r) return t[p].m;
    int m = t[p].l + t[p].r >> 1;
    if (r <= m)
      return query(p << 1, l, r);
    else if (l > m)
      return query((p << 1) + 1, l, r);
    else
      return max(query(p << 1, l, m), query((p << 1) + 1, m + 1, r));
  }
} t0, t1;
int c[maxn];
map<int, int> height;
void insert(int p) {
  while (p <= n) c[p]++, p += p & (-p);
}
int getrank(int p) {
  int ret = 0;
  while (p) ret += c[p], p -= p & (-p);
  return ret;
}
void remove(int p) {
  while (p <= n) c[p]--, p += p & (-p);
}
int main() {
  scanf("%d%d", &n, &m);
  t0.build(1, 1, n);
  t1.build(1, 1, maxl);
  for (int tsp = (1); tsp <= (m); ++tsp) {
    scanf("%d", &ty);
    if (ty == 1) {
      scanf("%d", &p);
      scanf("%d", &h[p]);
      insert(p);
      f[p] = t0.query(1, p + 1, n) + 1;
      int cnt = 0;
      while (tmp.size()) {
        buff[++cnt] = tmp.top();
        tmp.pop();
      }
      for (int i = (1); i <= (cnt); ++i)
        buff[i].first++, height[buff[i].second]++;
      for (int i = (1); i <= (cnt); ++i)
        if (buff[i].second > p && buff[i].first > h[p])
          f[p] = max(f[p], f[buff[i].second] + 1);
      for (int i = (1); i <= (cnt); ++i)
        if (buff[i].first == 11)
          t0.modify(1, buff[i].second, f[buff[i].second]);
        else
          tmp.push(buff[i]);
      tmp.push((make_pair(h[p], p)));
      height[p] = h[p];
      h[p] += 200000 - tsp;
      cnt = 0;
      for (int i = (200002 - tsp); i <= (200011 - tsp); ++i)
        if (b[i]) buf[++cnt] = b[i];
      sort(buf + 1, buf + cnt + 1);
      for (int i = (cnt); i >= (1); --i) {
        if (p > buf[i] && h[buf[i]] < h[p])
          f[buf[i]] = max(f[buf[i]], f[p] + 1);
        for (int j = (i + 1); j <= (cnt); ++j)
          if (h[buf[j]] > h[buf[i]]) f[buf[i]] = max(f[buf[i]], f[buf[j]] + 1);
        if (height[buf[i]] > 10) t0.modify(1, buf[i], f[buf[i]]);
        if (getrank(buf[i]) > 10) t1.modify(1, h[buf[i]], f[buf[i]]);
      }
      b[h[p]] = p;
      cnt = 0;
      for (set<int>::iterator i = trees.begin(); i != trees.end(); ++i) {
        buf[++cnt] = *i;
        if (cnt == 10) break;
      }
      if (cnt == 10 && p > buf[10])
        t1.modify(1, h[p], f[p]);
      else if (cnt == 10)
        t1.modify(1, h[buf[10]], f[buf[10]]);
      trees.insert(p);
    } else {
      int cnt = 0;
      while (tmp.size()) {
        buff[++cnt] = tmp.top();
        tmp.pop();
      }
      for (int i = (1); i <= (cnt); ++i)
        buff[i].first++, height[buff[i].second]++;
      for (int i = (1); i <= (cnt); ++i)
        if (buff[i].first == 11)
          t0.modify(1, buff[i].second, f[buff[i].second]);
        else
          tmp.push(buff[i]);
      int x, p;
      scanf("%d", &x);
      set<int>::iterator i;
      cnt = 0;
      for (i = trees.begin(); i != trees.end(); ++i) {
        buf[++cnt] = *i;
        if (cnt == x) {
          p = *i, --cnt;
          break;
        }
      }
      for (i++; i != trees.end(); ++i) {
        buf[++cnt] = *i;
        if (cnt == 10) break;
      }
      trees.erase(p);
      b[h[p]] = 0;
      remove(p);
      if (cnt == 10 && i != trees.end()) t1.modify(1, h[*i], 0);
      t0.modify(1, p, 0);
      h[p] = f[p] = 0;
      for (int i = (cnt); i >= (1); --i) {
        f[buf[i]] = t1.query(1, h[buf[i]], maxl) + 1;
        for (int j = (i + 1); j <= (cnt); ++j)
          if (h[buf[i]] < h[buf[j]]) f[buf[i]] = max(f[buf[i]], f[buf[j]] + 1);
        if (height[buf[i]] > 10) t0.modify(1, buf[i], f[buf[i]]);
        if (getrank(buf[i]) > 10) t1.modify(1, h[buf[i]], f[buf[i]]);
      }
      cnt = 0;
      while (tmp.size()) {
        buff[++cnt] = tmp.top();
        tmp.pop();
      }
      for (int i = (1); i <= (cnt); ++i)
        if (buff[i].second != p) tmp.push(buff[i]);
    }
    int ans = t1.query(1, 1, maxl);
    int cnt = 0;
    for (set<int>::iterator i = trees.begin(); i != trees.end(); ++i) {
      ++cnt;
      ans = max(ans, f[*i]);
      if (cnt > 10) break;
    }
    printf("%d\n", ans);
  }
  return 0;
}
