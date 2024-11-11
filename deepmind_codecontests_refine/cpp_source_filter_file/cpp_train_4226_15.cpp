#include <bits/stdc++.h>
using namespace std;
int a, b, c, d, n, m, s, g;
long long ans;
int B[205], sz[205];
pair<int, pair<int, int> > p, p1;
set<pair<int, pair<int, int> > > st;
set<pair<int, int> > v[205];
vector<pair<pair<int, int>, pair<int, int> > > V;
int get_col(int x) {
  if (B[x] == x) return x;
  B[x] = get_col(B[x]);
  return B[x];
}
void col(int x, int y) {
  sz[get_col(y)] += sz[get_col(x)];
  B[get_col(x)] = get_col(y);
}
void dfs(int x, int y, int z, pair<int, pair<int, int> > pr) {
  if (x == z) {
    p = pr;
    return;
  }
  for (set<pair<int, int> >::iterator it = v[x].begin(); it != v[x].end();
       it++) {
    if ((*it).second == y) continue;
    p1.first = (*it).first;
    p1.second.first = (*it).second;
    p1.second.second = x;
    dfs((*it).second, x, z, p1);
  }
}
int main() {
  cin >> n >> m >> g >> s;
  for (int i = 1; i <= n; i++) {
    B[i] = i;
    sz[i] = 1;
  }
  for (int i = 1; i <= m; i++) {
    cin >> a >> b >> c >> d;
    if (a == b) continue;
    V.push_back({{c, d}, {a, b}});
  }
  sort(V.begin(), V.end());
  ans = -1;
  for (int i = 0; i < V.size(); i++) {
    a = V[i].second.first;
    b = V[i].second.second;
    c = V[i].first.first;
    d = V[i].first.second;
    if (get_col(a) != get_col(b)) {
      col(a, b);
      v[a].insert({d, b});
      v[b].insert({d, a});
      if (a < b) swap(a, b);
      st.insert({d, {a, b}});
    } else {
      dfs(a, 0, b, {0, {0, 0}});
      if (p.first > d) {
        if (p.second.first < p.second.second)
          swap(p.second.first, p.second.second);
        v[p.second.first].erase({p.first, p.second.second});
        v[p.second.second].erase({p.first, p.second.first});
        st.erase(p);
        v[a].insert({d, b});
        v[b].insert({d, a});
        if (a < b) swap(a, b);
        st.insert({d, {a, b}});
      }
    }
    if (sz[get_col(1)] == n) {
      if (ans == -1)
        ans = (long long)g * (long long)c +
              (long long)s * (long long)((*st.rbegin()).first);
      else
        ans = min(ans, (long long)g * (long long)c +
                           (long long)s * (long long)((*st.rbegin()).first));
    }
  }
  if (ans == -1)
    cout << -1;
  else
    cout << ans;
}
