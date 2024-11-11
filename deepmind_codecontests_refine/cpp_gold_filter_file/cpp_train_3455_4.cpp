#include <bits/stdc++.h>
using namespace std;
void myInit();
int mpow(int base, int exp);
void ipgraph(int m);
void dfs(int u, int par);
const int MOD = 1000000007;
const int N = 3e5, M = N;
vector<int> g[N];
int a[N];
int main() {
  myInit();
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n, k, i = 1;
  string s;
  cin >> n >> k >> s;
  if (n == 1 && k > 0) {
    cout << "0\n";
    return 0;
  }
  if (k > 0 && s[0] != '1') {
    s[0] = '1';
    k--;
  }
  while (k > 0 && i < n) {
    if (s[i] != '0') {
      s[i] = '0';
      k--;
    }
    i++;
  }
  cout << s << endl;
  return 0;
}
void myInit() {}
int mpow(int base, int exp) {
  base %= MOD;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((long long)result * base) % MOD;
    base = ((long long)base * base) % MOD;
    exp >>= 1;
  }
  return result;
}
void ipgraph(int n, int m) {
  int i, u, v;
  while (m--) {
    cin >> u >> v;
    g[u - 1].push_back(v - 1);
    g[v - 1].push_back(u - 1);
  }
}
void dfs(int u, int par) {
  for (int v : g[u]) {
    if (v == par) continue;
    dfs(v, u);
  }
}
