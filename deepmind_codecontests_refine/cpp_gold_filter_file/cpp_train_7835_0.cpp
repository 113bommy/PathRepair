#include <bits/stdc++.h>
using namespace std;
mt19937_64 rang(
    chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
  uniform_int_distribution<int> uid(0, lim - 1);
  return uid(rang);
}
int mpow(int base, int exp);
void ipgraph(int n, int m);
void dfs(int u, int par);
const int mod = 1000000007;
const int N = 3e5, M = N;
vector<int> g[N];
int a[N];
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int tc = 1;
void solve() {
  long long int n, nsum = 0, psum = 0;
  cin >> n;
  vector<long long> ar(n);
  for (int i = 0; i < n; i++) {
    cin >> ar[i];
    if (ar[i] < 0)
      nsum += ar[i];
    else
      psum += ar[i];
  }
  if (nsum + psum == 0) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  int c = 0;
  if (abs(nsum) > psum) {
    sort(ar.begin(), ar.end());
    for (auto i : ar) {
      if (i == 0)
        c++;
      else
        cout << i << " ";
    }
    while (c--) {
      cout << "0 ";
    }
  } else {
    sort(ar.begin(), ar.end(), greater<int>());
    for (auto i : ar) {
      if (i == 0)
        c++;
      else
        cout << i << " ";
    }
    while (c--) {
      cout << "0 ";
    }
  }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  srand(chrono::high_resolution_clock::now().time_since_epoch().count());
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
int mpow(int base, int exp) {
  base %= mod;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((long long)result * base) % mod;
    base = ((long long)base * base) % mod;
    exp >>= 1;
  }
  return result;
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
void dfs(int u, int par) {
  for (int v : g[u]) {
    if (v == par) continue;
    dfs(v, u);
  }
}
