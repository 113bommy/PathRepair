#include <bits/stdc++.h>
using namespace std;
inline int read();
const int maxn = 4e5 + 5;
int n;
int id[maxn][2], last;
pair<int, int> q[maxn], edge[maxn << 1];
vector<int> v[maxn << 2];
struct EDGE {
  int tim, ty, first, second;
} e[maxn << 1];
bool operator<(const EDGE& a, const EDGE& b) {
  if (a.first != b.first) return a.first < b.first;
  if (a.second != b.second) return a.second < b.second;
  return a.tim < b.tim;
}
namespace UF {
int top;
int fa[maxn], siz[maxn], stk[maxn];
void Init(int n) {
  top = 0;
  for (int i = 1; i <= n; ++i) fa[i] = i, siz[i] = 0;
}
int Find(int first) { return fa[first] == first ? first : Find(fa[first]); }
void Merge(int e) {
  int first = Find(edge[e].first), second = Find(edge[e].second);
  if (first == second) return;
  if (siz[first] < siz[second]) swap(first, second);
  if (siz[first] == siz[second]) stk[++top] = first, ++siz[first];
  stk[++top] = second, fa[second] = first;
}
void Cancel(int l) {
  for (int i = stk[top]; top != l; --top, i = stk[top])
    if (fa[i] == i)
      --siz[i];
    else
      fa[i] = i;
}
}  // namespace UF
namespace SEG {
bool vis[maxn << 1];
void Insert(int rt, int l, int r, int ql, int qr, int e) {
  if (l >= ql && r <= qr) {
    v[rt].push_back(e);
    return;
  }
  if (((l + r) >> 1) >= ql) Insert((rt << 1), l, ((l + r) >> 1), ql, qr, e);
  if (((l + r) >> 1) < qr)
    Insert((rt << 1 | 1), ((l + r) >> 1) + 1, r, ql, qr, e);
}
void Divide(int rt, int l, int r) {
  using namespace UF;
  int pre = top;
  for (int i = v[rt].size() - 1; i >= 0; --i)
    if (vis[v[rt][i]]) Merge(v[rt][i]);
  if (l == r) {
    if (q[l].first) {
      int first = (q[l].first + last - 1) % n + 1,
          second = (q[l].second + last - 1) % n + 1;
      printf("%d", last = (Find(first) == Find(second)));
    } else
      vis[id[l][last]] ^= 1;
  } else {
    Divide((rt << 1), l, ((l + r) >> 1));
    Divide((rt << 1 | 1), ((l + r) >> 1) + 1, r);
  }
  Cancel(pre);
}
}  // namespace SEG
inline void Work() {
  n = read();
  int m = read(), opt_cnt = 0, edge_cnt = 0;
  for (int i = 1; i <= m; ++i) {
    int op = read(), first = read(), second = read();
    if (op == 1) {
      if (first > second) swap(first, second);
      e[++opt_cnt] = (EDGE){i, 0, first, second};
      first = first % n + 1, second = second % n + 1;
      if (first > second) swap(first, second);
      e[++opt_cnt] = (EDGE){i, 1, first, second};
    } else
      q[i] = make_pair(first, second);
  }
  sort(e + 1, e + opt_cnt + 1);
  edge[++edge_cnt] = make_pair(e[1].first, e[1].second);
  for (int i = 2; i <= opt_cnt; ++i) {
    id[e[i - 1].tim][e[i - 1].ty] = edge_cnt;
    if (e[i - 1].first == e[i].first && e[i - 1].second == e[i].second) {
      SEG::Insert(1, 1, m, e[i - 1].tim + 1, e[i].tim, edge_cnt);
    } else {
      if (e[i - 1].tim < m) SEG::Insert(1, 1, m, e[i - 1].tim + 1, m, edge_cnt);
      edge[++edge_cnt] = make_pair(e[i].first, e[i].second);
    }
  }
  UF::Init(n);
  SEG::Divide(1, 1, m);
}
int main() {
  Work();
  return 0;
}
inline int read() {
  char c;
  bool type = 1;
  while ((c = getchar()) < '0' || c > '9')
    if (c == '-') type = 0;
  int ans = c ^ 48;
  while ((c = getchar()) >= '0' && c <= '9')
    ans = (ans << 3) + (ans << 1) + (c ^ 48);
  return type ? ans : -ans;
}
