#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : " << arg1 << "\n";
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
int mpow(int base, int exp);
void ipgraph(int n, int m);
void dfs(int u, int par);
const int N = 100005, M = 100005;
vector<long long> g[N];
int a[N];
void solve() {
  long long i, j, n, m, k;
  string s;
  cin >> s;
  n = s.length();
  map<char, long long> make_pair;
  long long ans = 1;
  for (i = 0; i < n; ++i) {
    make_pair[s[i]]++;
    if (make_pair[s[i]] > 1) ans = max(2LL, ans);
  }
  for (i = 0; i < 26; ++i) {
    for (j = 0; j < 26; ++j) {
      char ch1 = 'a' + i;
      char ch2 = 'a' + j;
      long long l = 0, r = 0, curr = 0;
      map<char, long long> tmp = make_pair;
      for (l = 0; l < n; ++l) {
        if (s[l] == ch2) tmp[ch2]--;
        if (s[l] == ch1) curr += tmp[ch2];
      }
      ans = max(ans, curr);
    }
  }
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  { solve(); }
}
int mpow(int base, int exp) {
  base %= ((int)1e9 + 7);
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((long long)result * base) % ((int)1e9 + 7);
    base = ((long long)base * base) % ((int)1e9 + 7);
    exp >>= 1;
  }
  return result;
}
void ipgraph(int n, int m) {
  int i, u, v;
  while (m--) {
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
}
void dfs(int u, int par) {
  for (int v : g[u]) {
    if (v == par) continue;
    dfs(v, u);
  }
}
