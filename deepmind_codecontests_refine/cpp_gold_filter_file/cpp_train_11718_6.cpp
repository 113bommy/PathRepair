#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void smin(T &a, const U &b) {
  if (a > b) a = b;
}
template <typename T, typename U>
inline void smax(T &a, const U &b) {
  if (a < b) a = b;
}
template <class T>
inline void gn(T &first) {
  char c, sg = 0;
  while (c = getchar(), (c > '9' || c < '0') && c != '-')
    ;
  for ((c == '-' ? sg = 1, c = getchar() : 0), first = 0; c >= '0' && c <= '9';
       c = getchar())
    first = (first << 1) + (first << 3) + c - '0';
  if (sg) first = -first;
}
template <class T1, class T2>
inline void gn(T1 &x1, T2 &x2) {
  gn(x1), gn(x2);
}
int power(int a, int b, int m, int ans = 1) {
  for (; b; b >>= 1, a = 1LL * a * a % m)
    if (b & 1) ans = 1LL * ans * a % m;
  return ans;
}
unsigned long long dp[100100];
vector<int> adj[100100];
int sz[100100];
void dfs(int u, int f = 0) {
  sz[u] = 1;
  for (int &v : adj[u]) {
    if (v == f) {
      swap(v, adj[u].back());
      adj[u].pop_back();
      break;
    }
  }
  vector<unsigned long long> vec;
  for (int v : adj[u]) {
    dfs(v, u);
    vec.push_back(dp[v]);
    sz[u] += sz[v];
  }
  sort(vec.begin(), vec.end());
  vec.push_back(sz[u]);
  vec.push_back(adj[u].size());
  dp[u] = 0;
  for (unsigned long long first : vec) dp[u] = dp[u] * 100102021 + first;
}
set<unsigned long long> s;
void redfs(int u, unsigned long long pre = 0, int psz = 0) {
  vector<unsigned long long> vec;
  vec.push_back(pre);
  for (int v : adj[u]) vec.push_back(dp[v]);
  sort(vec.begin(), vec.end());
  vec.push_back(sz[u] + psz);
  vec.push_back(adj[u].size() + (psz > 0));
  unsigned long long ans = 0;
  for (unsigned long long first : vec) ans = ans * 100102021 + first;
  if (adj[u].size() + (psz > 0) < 4) s.insert(ans);
  for (int v : adj[u]) {
    vec.clear();
    vec.push_back(pre);
    int ppsz = psz + 1;
    for (int w : adj[u])
      if (v != w) vec.push_back(dp[w]), ppsz += sz[w];
    sort(vec.begin(), vec.end());
    vec.push_back(ppsz);
    vec.push_back(adj[u].size() - (!psz));
    unsigned long long ppre = 0;
    for (unsigned long long first : vec) ppre = ppre * 100102021 + first;
    redfs(v, ppre, ppsz);
  }
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    gn(u, v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1);
  redfs(1);
  cout << s.size() << endl;
  return 0;
}
