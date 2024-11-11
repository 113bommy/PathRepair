#include <bits/stdc++.h>
using namespace std;
string itosm(long long x) {
  if (x == 0) return "0";
  string ans = "";
  while (x > 0) {
    ans += ((x % 10) + '0');
    x /= 10;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}
long long stoim(string str) {
  long long ans = 0;
  long long k = 1;
  int p = 0;
  if (str[0] == '-') p++;
  for (int i = str.length() - 1; i >= p; i--) {
    ans += (str[i] - '0') * k;
    k *= 10;
  }
  return ans;
}
const long long infll = 1e18 + 3;
const int inf = 1009000999;
const long double eps = 1e-7;
const int maxn = 1e6 + 1146;
const int baseint = 1000200013;
const long long basell = 1e18 + 3;
const long double PI = acos(-1.0);
const long long mod = 1e9 + 9;
vector<int> g[maxn];
int d[maxn];
int lvl[maxn];
bool del[maxn];
void dfs(int v, int an) {
  for (int to : g[v]) {
    if (to == an) continue;
    lvl[v] = lvl[to] + 1;
    dfs(to, v);
  }
}
void solve() {
  int n;
  cin >> n;
  if (n % 2 == 0) {
    cout << "NO";
    return;
  }
  cout << "YES\n";
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    if (x == 0) continue;
    g[i].push_back(x);
    g[x].push_back(i);
  }
  dfs(1, -1);
  set<pair<int, int> > q;
  for (int v = 1; v <= n; v++) {
    d[v] = g[v].size();
    if (g[v].size() % 2 == 0) q.insert({lvl[v], v});
  }
  vector<int> ans;
  while (!q.empty()) {
    int v = (*q.rbegin()).second;
    q.erase({lvl[v], v});
    ans.push_back(v);
    del[v] = 1;
    for (int to : g[v]) {
      d[to]--;
      if (d[to] % 2 == 0) {
        if (!del[to]) q.insert({lvl[to], to});
      } else {
        q.erase({lvl[to], to});
      }
    }
  }
  for (int v : ans) cout << v << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  ;
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
