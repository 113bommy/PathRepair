#include <bits/stdc++.h>
using namespace std;
template <class S, class T>
ostream& operator<<(ostream& o, const pair<S, T>& p) {
  return o << "(" << p.first << "," << p.second << ")";
}
template <class T>
ostream& operator<<(ostream& o, const vector<T>& vc) {
  o << "sz = " << vc.size() << endl << "[";
  for (const T& v : vc) o << v << ",";
  o << "]";
  return o;
}
int N, M;
vector<pair<int, int> > G[100000];
bool vis[100000];
bool f[100000];
vector<int> ad;
bool dfs(int v, int p, bool B) {
  vis[v] = 1;
  for (pair<int, int> e : G[v]) {
    int u = e.first;
    if (u == p) continue;
    if (vis[u]) {
      if ((e.second ^ f[u] ^ f[v]) != B) return false;
      continue;
    }
    if ((e.second ^ f[v]) != B) {
      ad.push_back(u);
      f[u] = 1;
    }
    if (!dfs(u, v, B)) return false;
  }
  return true;
}
void dfss(vector<int>& vs, int v) {
  vis[v] = 1;
  vs.push_back(v);
  for (pair<int, int> e : G[v]) {
    int u = e.first;
    if (!vis[u]) dfss(vs, u);
  }
}
int main() {
  cin >> N >> M;
  for (int i = 0; i < (int)(M); i++) {
    int a, b;
    char c;
    cin >> a >> b >> c;
    a--, b--;
    G[a].push_back(pair<int, int>(b, c == 'B'));
    G[b].push_back(pair<int, int>(a, c == 'B'));
  }
  bool ok1 = 1, ok2 = 1;
  vector<int> ans1, ans2;
  for (int i = 0; i < (int)(N); i++)
    if (!vis[i]) {
      ad.clear();
      vector<int> t;
      bool ok = 0;
      vector<int> vs;
      dfss(vs, i);
      for (int v : vs) vis[v] = 0;
      if (dfs(i, -1, 0) && (!ok || t.size() > ad.size())) t = ad, ok = 1;
      ad.clear();
      for (int v : vs) vis[v] = 0, f[v] = 0;
      f[i] = 1, ad.push_back(i);
      if (dfs(i, -1, 0) && (!ok || t.size() > ad.size())) t = ad, ok = 1;
      ad.clear();
      for (int v : vs) vis[v] = 0, f[v] = 0;
      if (ok) {
        for (int a : t) ans1.push_back(a);
      } else {
        ok1 = 0;
      }
      ok = 0;
      t.clear();
      if (dfs(i, -1, 1) && (!ok || t.size() > ad.size())) t = ad, ok = 1;
      ad.clear();
      for (int v : vs) vis[v] = 0, f[v] = 0;
      f[i] = 1, ad.push_back(i);
      if (dfs(i, -1, 1) && (!ok || t.size() > ad.size())) t = ad, ok = 1;
      ad.clear();
      for (int v : vs) vis[v] = 1;
      if (ok) {
        for (int a : t) ans2.push_back(a);
      } else {
        ok2 = 0;
      }
    }
  if (!ok1 && !ok2) {
    puts("-1");
    return 0;
  }
  vector<int> ans;
  if (ok1) ans = ans1;
  if (!ok1 && ok2) ans = ans2;
  if (ok1 && ok2) {
    if (ans1.size() > ans2.size()) ans = ans2;
  }
  cout << ans.size() << endl;
  for (int a : ans) cout << a + 1 << endl;
}
