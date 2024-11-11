#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:36777216")
using namespace std;
long long mod = 1e9 + 7;
long double eps = 1e-12;
long double pi = acosl(-1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ifstream in("input.txt");
ofstream out("output.txt");
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using uc = unsigned char;
using us = unsigned short;
ll phi[100050];
ll a[100050];
vector<int> g[100050];
int used[100050];
int step = 1;
void solve() {
  phi[1] = 1;
  g[1].push_back(1);
  for (int i = 2; i < 100050; i++) {
    phi[i] = i - 1;
    g[i].push_back(1);
    g[i].push_back(i);
  }
  for (ll i = 2; i < 100050; i++) {
    for (ll j = 2; j * i < 100050; j++) {
      phi[j * i] -= phi[i];
      g[i * j].push_back(j);
    }
  }
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  ll ans = 0;
  for (ll i = 1; i <= n; i++) {
    ll res = 0;
    ll p = 1;
    unordered_map<int, int> m;
    for (ll t = 1; t * i <= n; t++) {
      for (auto x : g[a[t * i]]) m[x]++;
    }
    for (auto x : m) {
      res += (((x.second * x.second) % mod) * phi[x.first]) % mod;
      if (res >= mod) res -= mod;
    }
    ans += res * phi[i] % mod;
    if (ans >= mod) ans -= mod;
  }
  cout << ans;
}
int main() {
  cout << setprecision(20) << fixed;
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  clock_t t1 = clock();
  ;
  int t = 1;
  int cs = 1;
  while (t--) {
    solve();
  }
  return 0;
}
