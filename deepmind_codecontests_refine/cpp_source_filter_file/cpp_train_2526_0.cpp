#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
const int mod = 1e9 + 7;
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b > 0)
    if (b & 1) {
      res = (long long)(res * 1ll * a);
      --b;
    } else {
      a = (long long)(a * 1ll * a);
      b >>= 1;
    }
  return (long long)res;
}
vector<vector<int>> g;
vector<bool> used;
int pred = -1;
int timer = 0;
vector<int> tin, tout;
void dfs(int v, int p = -1) {
  used[v] = true;
  tin[v] = timer;
  timer++;
  for (auto to : g[v]) {
    if (!used[to]) dfs(to);
  }
  tout[v] = timer;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int q;
  cin >> q;
  while (q--) {
    int n, a, b, da, db;
    cin >> n >> a >> b >> da >> db;
    vector<vector<int>> g;
    g.resize(n);
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    if (da * 2 >= db) {
      cout << "Alice" << endl;
      continue;
    }
    int starta = a - 1;
    int startb = b - 1;
    vector<bool> used(n);
    queue<int> q;
    used[starta] = true;
    q.push(starta);
    vector<int> d(n);
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (auto to : g[v]) {
        if (!used[to]) {
          used[to] = true;
          q.push(to);
          d[to] = d[v] + 1;
        }
      }
    }
    int ind_max = 0;
    int maxi = 0;
    for (int i = 0; i < n; i++) {
      if (d[i] > maxi) {
        maxi = d[i];
        ind_max = i;
      }
    }
    if (abs(d[startb]) <= da) {
      cout << "Alice" << endl;
      continue;
    }
    used.clear();
    used.resize(n);
    used[ind_max] = true;
    q.push(ind_max);
    d.clear();
    d.resize(n);
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (auto to : g[v]) {
        if (!used[to]) {
          used[to] = true;
          q.push(to);
          d[to] = d[v] + 1;
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      ans = max(ans, d[i]);
    }
    if (double(ans / da) >= 2.0) {
      cout << "Bob" << endl;
    } else {
      cout << "Alice" << endl;
    }
  }
  return 0;
}
