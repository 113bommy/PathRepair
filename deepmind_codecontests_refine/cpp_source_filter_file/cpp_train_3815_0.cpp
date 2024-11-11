#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
int extra = 0;
vector<int> graph[N];
int par[N];
int sz[N];
int n, m;
int power(int a, int b) {
  if (!b) {
    return 1;
  }
  long long ans = power(a, b / 2);
  ans = ans * ans;
  ans = ans % mod;
  if (b % 2) {
    ans = ans * a;
    ans = ans % mod;
  }
  return ans;
}
int get(int v) {
  if (par[v] == v) {
    return v;
  }
  return par[v] = get(par[v]);
}
void add(int v, int u) {
  v = get(v);
  u = get(u);
  if (v == u) {
    extra++;
    return;
  }
  par[u] = v;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    par[i] = i;
  }
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    v--;
    u--;
    add(v, u);
    cout << power(2, extra) - 1 << endl;
  }
}
