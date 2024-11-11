#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200 * 100 * 10 + 10, mod = 1e9 + 7;
vector<long long> a[MAXN];
long long pre[MAXN], suf[MAXN];
bool vis[MAXN];
long long dp_up[MAXN], dp_down[MAXN];
long long ans_f[MAXN];
void dfs1(int v) {
  vis[v] = true;
  vector<int> u;
  for (int i = 0; i < a[v].size(); i++)
    if (vis[a[v][i]] == false) {
      dfs1(a[v][i]);
      u.push_back(a[v][i]);
    }
  long long ans = 1;
  for (int i = 0; i < u.size(); i++) ans = (ans * (dp_down[u[i]] + 1)) % mod;
  ans = ans % mod;
  dp_down[v] = ans;
}
void dfs2(int v) {
  vis[v] = true;
  long long ans = 1;
  vector<int> u;
  pre[0] = 1;
  for (int i = 0; i < a[v].size(); i++)
    if (vis[a[v][i]] == false) u.push_back(a[v][i]);
  suf[u.size()] = 1;
  for (int i = 0; i < u.size(); i++)
    pre[i + 1] = (pre[i] * (dp_down[u[i]] + 1)) % mod;
  for (int i = u.size() - 1; i > -1; i--)
    suf[i] = (suf[i + 1] * (dp_down[u[i]] + 1)) % mod;
  for (int i = 0; i < u.size(); i++)
    dp_up[u[i]] = ((dp_up[v] * ((pre[i] * suf[i + 1]) % mod)) + 1) % mod;
  for (int i = 0; i < a[v].size(); i++)
    if (vis[a[v][i]] == false) {
      dfs2(a[v][i]);
    }
}
int main() {
  int n, x;
  cin >> n;
  dp_up[1] = 1;
  for (int i = 0; i < n + 1; i++) dp_down[i] = 1;
  for (int i = 2; i <= n; i++) {
    cin >> x;
    a[x].push_back(i);
    a[i].push_back(x);
  }
  dfs1(1);
  for (int i = 0; i <= n; i++) vis[i] = false;
  dfs2(1);
  for (int i = 1; i < n + 1; i++) cout << (dp_up[i] * dp_down[i]) % mod << ' ';
  return 0;
}
