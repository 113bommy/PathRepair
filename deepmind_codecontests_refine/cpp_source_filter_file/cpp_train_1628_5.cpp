#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 7, maxd = 670000 + 7, mod = 1e9 + 7;
const int INF = 0x7f7f7f7f;
struct node {
  vector<int> v;
  vector<pair<int, int> > q;
};
map<int, node> mp;
struct edge {
  int s, t, w;
} e[maxn];
bool ans[maxn];
int f[maxn], size_[maxn];
int s[maxn];
int find_(int i) { return f[i] ? find_(f[i]) : i; }
int union_(int i, int j) {
  f[j] = i;
  size_[i] += size_[j];
  return j;
}
int merge_(int i, int j) {
  i = find_(i), j = find_(j);
  if (i == j) return 0;
  return size_[i] > size_[j] ? union_(i, j) : union_(j, i);
}
void split(int i) {
  size_[f[i]] -= size_[i];
  f[i] = 0;
}
int main() {
  int n, m, qnum, x, y;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d %d %d", &e[i].s, &e[i].t, &e[i].w);
    mp[e[i].w].v.push_back(i);
  }
  scanf("%d", &qnum);
  for (int i = 0; i < qnum; ++i) {
    scanf("%d", &x);
    while (x--) {
      scanf("%d", &y);
      mp[e[y].w].q.push_back({i, y});
    }
  }
  for (int i = 1; i <= n; ++i) size_[i] = 1;
  for (auto& p : mp) {
    auto& q = p.second.q;
    sort(q.begin(), q.end());
    int cnt = 0;
    for (int j = 0; j < q.size(); ++j) {
      int t = merge_(e[q[j].second].s, e[q[j].second].t);
      if (!t)
        ans[q[j].first] = true;
      else
        s[++cnt] = t;
      if (j + 1 == q.size() || q[j].first != q[j + 1].first) {
        while (cnt) split(s[cnt--]);
      }
    }
    for (int edge : p.second.v) merge_(e[edge].s, e[edge].t);
  }
  for (int i = 0; i < qnum; ++i) printf(ans[i] ? "NO\n" : "Yes\n");
  return 0;
}
