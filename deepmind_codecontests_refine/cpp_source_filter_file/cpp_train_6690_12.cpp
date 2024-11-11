#include <bits/stdc++.h>
using namespace std;
vector<string> vec_splitter(string s) {
  s += ',';
  vector<string> res;
  while (!s.empty()) {
    res.push_back(s.substr(0, s.find(',')));
    s = s.substr(s.find(',') + 1);
  }
  return res;
}
void debug_out(vector<string> __attribute__((unused)) args,
               __attribute__((unused)) int idx,
               __attribute__((unused)) int LINE_NUM) {
  cerr << endl;
}
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
  if (idx > 0)
    cerr << ", ";
  else
    cerr << "Line(" << LINE_NUM << ") ";
  stringstream ss;
  ss << H;
  cerr << args[idx] << " = " << ss.str();
  debug_out(args, idx + 1, LINE_NUM, T...);
}
template <class T>
bool ckmin(T& a, T& b) {
  bool r = a > b;
  a = min(a, b);
  return r;
}
template <class T>
bool ckmax(T& a, T& b) {
  bool r = a < b;
  a = max(a, b);
  return r;
}
const int MOD = 1e9 + 7;
const long long INF = 1e18;
const int MAXN = 5e5 + 5;
vector<int> adj[MAXN];
int h[MAXN];
int p[MAXN];
bool vis[MAXN];
int n, m;
bool dfs(int c) {
  vis[c] = true;
  int cl = (n + 1) / 2;
  if (h[c] >= cl) {
    cout << "PATH" << '\n';
    ;
    cout << h[c] << '\n';
    ;
    cout << c;
    return true;
  }
  for (auto& nxt : adj[c]) {
    if (!vis[nxt]) {
      h[nxt] = h[c] + 1;
      p[nxt] = c;
      if (dfs(nxt)) {
        cout << " " << c;
        return true;
      }
    }
  }
  return false;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  for (int a = 0; a < T; a++) {
    cin >> n >> m;
    for (int i = 0; i <= n; i++) {
      adj[i].clear();
      vis[i] = false;
    }
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    h[1] = 0;
    p[1] = -1;
    if (dfs(1)) {
      cout << '\n';
      ;
    } else {
      cout << "PAIRING" << '\n';
      ;
      map<int, int> track;
      vector<pair<int, int> > ans;
      for (int i = 1; i <= n; i++) {
        if (track.count(h[i]) && track[h[i]] != 0) {
          ans.push_back({i, track[h[i]]});
          track[h[i]] = 0;
        } else {
          track[h[i]] = i;
        }
      }
      cout << ans.size() << '\n';
      ;
      for (auto& v : ans) {
        cout << v.first << " " << v.second << '\n';
        ;
      }
    }
  }
}
