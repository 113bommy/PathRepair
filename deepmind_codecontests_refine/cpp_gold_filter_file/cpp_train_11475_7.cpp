#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-16;
const long long MOD = (int)998244353;
const int INF = 2 * (int)1e9 + 3;
const int NHASH = 2;
const int MAXN = 41;
inline long long mod(long long x, long long m = MOD) {
  if (x < 0) x += m;
  return (x % m);
}
int n;
vector<int> p, c, a;
vector<vector<int> > ch;
vector<int> l, h;
vector<int> cnt;
int top = 1;
bool impossible = false;
int check(int v, int num) {
  if (ch[v].size() + 1 == num) {
    return h[v] + 1;
  }
  int nc = 0;
  for (auto u : ch[v]) {
    if (nc + ch[u].size() + 1 == num) {
      return (h[u] + 1);
    } else if (nc + ch[u].size() + 1 > num && nc < num)
      return check(u, num - nc);
    nc += ch[u].size() + 1;
  }
}
vector<int> dfs(int v) {
  vector<int> res;
  for (auto u : ch[v]) {
    auto resu = dfs(u);
    res.insert(res.end(), resu.begin(), resu.end());
  }
  if (c[v] > res.size()) {
    cout << "NO";
    exit(0);
  }
  res.insert(res.begin() + c[v], v);
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  p = vector<int>(n + 1);
  c = vector<int>(n + 1);
  ch = vector<vector<int> >(n + 1);
  a = vector<int>(n + 1, 1);
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
    p[i];
    cin >> c[i];
    ch[p[i]].push_back(i);
  }
  vector<int> ans = dfs(ch[0][0]);
  for (int i = 0; i < n; ++i) a[ans[i]] = i + 1;
  cout << "YES\n";
  for (int i = 1; i <= n; ++i) cout << a[i] << " ";
  return 0;
}
