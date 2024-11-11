#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1000000007;
const long long int N = 3e5, M = N;
vector<int> g[N];
long long int a[N];
long long int mpow(long long int base, long long int exp) {
  base %= mod;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((long long int)result * base) % mod;
    base = ((long long int)base * base) % mod;
    exp >>= 1;
  }
  return result;
}
void ipgraph(long long int n, long long int m) {
  long long int i, u, v;
  while (m--) {
    cin >> u >> v;
    g[u - 1].push_back(v - 1);
    g[v - 1].push_back(u - 1);
  }
}
int sgn(long long int n) {
  if (n > 0) {
    return 1;
  } else {
    return -1;
  }
}
long long int max_digit(long long int n) {
  long long int lar = 0;
  while (n) {
    long long int r = n % 10;
    lar = max(r, lar);
    n = n / 10;
  }
  return lar;
}
long long int min_digit(long long int n) {
  long long int lar = 9;
  while (n) {
    long long int r = n % 10;
    lar = min(r, lar);
    n = n / 10;
  }
  return lar;
}
int prime(long long int n) {
  for (long long int i = 2; i < n; i++) {
    if (n % i == 0) {
      return 0;
    }
  }
  return 1;
}
void dfs(long long int u, long long int par) {
  for (int v : g[u]) {
    if (v == par) continue;
    dfs(v, u);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  long long int n, m;
  cin >> n >> m;
  if (n * 3 >= m)
    cout << 0;
  else
    cout << n * 3 - 2;
  return 0;
}
