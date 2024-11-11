#include <bits/stdc++.h>
using namespace std;
const int eps = 1e-6;
const int inf = (1 << 30);
inline int read() {
  char c;
  int f = 1;
  while ((c = getchar()) < '0' || c > '9')
    if (c == '-') f = -1;
  int res = c - '0';
  while ((c = getchar()) >= '0' && c <= '9') res = res * 10 + c - '0';
  return res * f;
}
const int N = 200010;
struct event {
  int x, y, id;
  bool type;
  event(){};
  event(int y, int x, bool type, int id) : y(y), x(x), type(type), id(id){};
  bool operator<(const event &a) const {
    if (x != a.x) return x < a.x;
    if (type != a.type) return type < a.type;
    return id < a.id;
  }
};
vector<event> e;
set<pair<int, int> > s;
vector<int> g[N], c[N];
int l[N], r[N], dp[N];
int n, m;
int F(int x, int y) { return min(r[x], r[y]) - max(l[x], l[y]); }
int dfs(int x) {
  if (dp[x] != -1) return dp[x];
  if (x == 1) return inf;
  int &ans = ::dp[x];
  ans = 0;
  for (int i = 0; i < g[x].size(); i++)
    ans = max(ans, min(c[x][i], dfs(g[x][i])));
  return ans;
}
int main() {
  n = read();
  m = read();
  n += 2;
  l[0] = l[1] = -inf;
  r[0] = r[1] = inf;
  for (int i = 2; i < n; i++) {
    int h;
    scanf("%d%d%d", &h, &l[i], &r[i]);
    e.push_back(event(h, l[i], 1, i));
    e.push_back(event(h, r[i], 0, i));
  }
  sort(e.begin(), e.end());
  s.insert(make_pair(m, 0));
  s.insert(make_pair(0, 1));
  for (int i = 0; i < e.size(); i++) {
    if (e[i].type == 0)
      s.erase(make_pair(e[i].y, e[i].id));
    else {
      set<pair<int, int> >::iterator iter =
          s.insert(make_pair(e[i].y, e[i].id)).first;
      int down = (--iter)->second;
      ++iter;
      int up = (++iter)->second;
      if (g[up].size() && g[up].back() == down) {
        g[up].pop_back();
        c[up].pop_back();
      }
      g[up].push_back(e[i].id);
      c[up].push_back(F(e[i].id, up));
      g[e[i].id].push_back(down);
      c[e[i].id].push_back(F(e[i].id, down));
    }
  }
  memset(dp, -1, sizeof(dp));
  cout << dfs(0) << endl;
  return 0;
}
