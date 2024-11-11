#include <bits/stdc++.h>
using namespace std;
template <class T>
void dbs(string str, T t) {
  cerr << str << " : " << t << "\n";
}
template <class T, class... S>
void dbs(string str, T t, S... s) {
  int idx = str.find(',');
  cerr << str.substr(0, idx) << " : " << t << ",";
  dbs(str.substr(idx + 1), s...);
}
template <class S, class T>
ostream& operator<<(ostream& os, const pair<S, T>& p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
template <class T>
ostream& operator<<(ostream& os, const vector<T>& p) {
  os << "[ ";
  for (auto& it : p) os << it << " ";
  return os << "]";
}
template <class T>
ostream& operator<<(ostream& os, const multiset<T>& p) {
  os << "[ ";
  for (auto& it : p) os << it << " ";
  return os << "]";
}
template <class S, class T>
ostream& operator<<(ostream& os, const map<S, T>& p) {
  os << "[ ";
  for (auto& it : p) os << it << " ";
  return os << "]";
}
template <class T>
void prc(T a, T b) {
  cerr << "[";
  for (T i = a; i != b; ++i) {
    if (i != a) cerr << ", ";
    cerr << *i;
  }
  cerr << "]\n";
}
vector<long long> adj[26];
vector<long long> vis(26, 0);
bool dfs(long long v, vector<long long>& ans) {
  vis[v] = 1;
  for (auto& j : adj[v]) {
    if (vis[j] == 1) return true;
    if (vis[j] == 0)
      if (dfs(j, ans)) return true;
  }
  vis[v] = 2;
  ans.push_back(v);
  return false;
}
void solve() {
  long long n;
  cin >> n;
  string s[n];
  for (long long i = 0; i < n; i++) cin >> s[i];
  for (long long i = 0; i < n; i++)
    for (long long j = (long long)(i + 1); j <= (long long)(n - 1); j++) {
      long long le = min(s[i].size(), s[j].size());
      bool flg = true;
      for (long long k = 0; k < le; k++) {
        if (s[i][k] != s[j][k]) {
          adj[s[j][k] - 'a'].push_back(s[i][k] - 'a');
          flg = false;
          break;
        }
      }
      if (flg) {
        if (s[i].size() > s[j].size()) {
          cout << "Impossible\n";
          return;
        }
      }
    }
  vector<long long> ans;
  for (long long i = 0; i < n; i++) {
    if (vis[i] == 0)
      if (dfs(i, ans)) {
        cout << "Impossible\n";
        return;
      }
  }
  vector<bool> mark(26, false);
  for (auto& j : ans) {
    cout << (char)(j + 'a');
    mark[j] = true;
  }
  for (long long k = 0; k < 26; k++)
    if (!mark[k]) cout << (char)(k + 'a');
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t = 1;
  while (t--) {
    solve();
  }
}
