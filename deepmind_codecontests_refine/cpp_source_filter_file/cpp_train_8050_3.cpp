#include <bits/stdc++.h>
using namespace std;
template <class T, class L>
bool smax(T& x, L y) {
  return x < y ? (x = y, 1) : 0;
}
template <class T, class L>
bool smin(T& x, L y) {
  return x > y ? (x = y, 1) : 0;
}
const int maxn = 2e5 + 17;
int n, m, gp[maxn], rate[maxn], cnt, sz[maxn];
map<int, pair<int, int> > p;
set<int> s[maxn];
vector<int> ag[maxn];
void dfs(int v, int rt = 0) {
  if (gp[v]) return;
  gp[v] = cnt, rate[v] = rt;
  s[cnt].insert(rt);
  sz[cnt]++;
  dfs((v + m) % n, rt + 1);
}
int main() {
  long long ans = 0;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++)
    if (!gp[i]) cnt++, dfs(i);
  int q;
  cin >> q;
  for (int id, h; q--;) {
    char c;
    scanf(" %c %d", &c, &id);
    if (c == '+') {
      scanf("%d", &h);
      int g = gp[h], r = rate[h];
      auto it = s[g].lower_bound(r);
      if (it == s[g].end()) it = s[g].begin(), ans += sz[g];
      ans += *it - r;
      p[id] = {g, *it};
      s[g].erase(it);
    } else {
      auto tmp = p[id];
      s[tmp.first].insert(tmp.second);
    }
  }
  printf("%d\n", ans);
  return 0;
}
