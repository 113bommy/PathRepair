#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 2;
vector<int> a[N + N];
struct SuffixAutomaton {
  vector<map<char, int> > g;
  vector<int> leng;
  vector<int> link;
  vector<int> pos;
  int last;
  SuffixAutomaton(string s) {
    g.push_back({});
    link.push_back(-1);
    leng.push_back(0);
    last = 0;
    pos.push_back(0);
    for (int i = 0; i < s.size(); ++i) {
      char c = s[i];
      g.push_back({});
      leng.push_back(i + 1);
      link.push_back(0);
      pos.push_back(i + 1);
      int R = g.size() - 1, P = last;
      last = R;
      while (~P && !g[P].count(c)) {
        g[P][c] = R;
        P = link[P];
      }
      if (P < 0) continue;
      int Q = g[P][c];
      if (leng[Q] == leng[P] + 1) {
        link[R] = Q;
        continue;
      }
      g.push_back(g[Q]);
      leng.push_back(leng[P] + 1);
      link.push_back(link[Q]);
      pos.push_back(i + 1);
      link[Q] = link[R] = g.size() - 1;
      while (~P && g[P].count(c) && g[P][c] == Q) {
        g[P][c] = g.size() - 1;
        P = link[P];
      }
    }
    for (int i = 1; i < g.size(); ++i) a[link[i]].push_back(i);
  }
};
int z[N];
int K[N];
int f[N];
string s, t;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> s >> t;
  s.erase(s.begin());
  int n = t.size();
  z[0] = 0;
  int L = 0, R = -1;
  for (int i = 1; i < n; ++i) {
    if (i < R) z[i] = min(R - i, z[i - L]);
    while (i + z[i] < n && t[i + z[i]] == t[z[i]]) ++z[i];
    if (i + z[i] > R) {
      L = i;
      R = i + z[i];
    }
  }
  SuffixAutomaton W(s);
  function<void(int)> dfs = [&](int u) {
    f[W.pos[u]] = max(f[W.pos[u]], K[u]);
    for (int v : a[u]) {
      K[v] = max(K[v], K[u]);
      dfs(v);
    }
  };
  int x = 0;
  for (int i = 0; i < n; ++i) {
    if (!W.g[x].count(t[i])) break;
    x = W.g[x][t[i]];
    K[x] = z[i + 1];
  }
  long long ans = 1ll * (s.size() + 1) * n;
  dfs(0);
  ans -= accumulate(f, f + N, 0ll);
  cout << ans << endl;
}
