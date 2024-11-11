#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
int MOD;
vector<int> edges[MAXN];
bool marked[MAXN];
inline long long mul(long long a, long long b) { return (a * b) % MOD; }
inline long long add(long long a, long long b) { return (a + b) % MOD; }
int dfs(int v) {
  if (marked[v]) return 0;
  marked[v] = true;
  int tot = 1;
  for (int i = 0; i < edges[v].size(); i++) tot += dfs(edges[v][i]);
  return tot;
}
int logPow(int a, int b) {
  if (b == 0) return 1;
  int x = logPow(a, b / 2);
  x = mul(x, x);
  if (b % 2)
    return mul(x, a);
  else
    return x;
}
int main() {
  int n, m;
  cin >> n >> m >> MOD;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  int sz = 0;
  int ans = 1;
  for (int i = 0; i < n; i++) {
    int tmp = dfs(i);
    if (tmp) {
      ans = mul(ans, tmp);
      sz++;
    }
  }
  if (sz == 1) {
    cout << 1 % MOD << endl;
    return 0;
  }
  for (int i = 0; i < sz - 2; i++) ans = mul(ans, n);
  cout << ans << endl;
}
