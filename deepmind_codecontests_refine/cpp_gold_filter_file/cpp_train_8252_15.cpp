#include <bits/stdc++.h>
using namespace std;
vector<int> g[10004];
vector<int> up(10004, 0), dep(10004, 0), ind(10004, 0);
int c = 0;
void ipgraph(int n, int m);
void dfs(int u, int par);
long long gcd(long long a, long long b);
unsigned long long factorial[1000004];
unsigned long long power(unsigned long long x, long long y, int p) {
  unsigned long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
unsigned long long modInverse(unsigned long long n, int p) {
  return power(n, p - 2, p);
}
unsigned long long nc(unsigned long long n, int r, int p) {
  if (r == 0) return 1;
  return (factorial[n] * modInverse(factorial[r], p) % p *
          modInverse(factorial[n - r], p) % p) %
         p;
}
vector<long long> f1(100005), f2(100005);
priority_queue<pair<int, pair<int, int> > > p;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << n << "\n";
    for (int i = 1; i <= n; i++) {
      cout << i << " ";
    }
    cout << endl;
  }
  return 0;
}
void dfs(int u, int par) {
  for (int v : g[u]) {
    if (v == par) continue;
    dep[v] = dep[u] + 1;
    dfs(v, u);
  }
}
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
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
