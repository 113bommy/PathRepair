#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
template <class T>
inline bool setmin(T &a, T b) {
  if (a > b) return a = b, 1;
  return 0;
}
template <class T>
inline bool setmax(T &a, T b) {
  if (a < b) return a = b, 1;
  return 0;
}
template <class T>
inline T fast(T a, T b, T mod) {
  long long res = 1;
  while (b) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}
template <class T>
inline T russian(T a, T b, T mod) {
  long long res = 0;
  while (b) {
    if (b & 1) res = (res + a) % mod;
    a = (a + a) % mod;
    b >>= 1;
  }
  return res;
}
template <class T>
istream &operator>>(istream &os, vector<T> &container) {
  for (auto &u : container) os >> u;
  return os;
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &container) {
  for (auto &u : container) os << u << " ";
  return os;
}
template <typename T>
inline T gcd(T a, T b) {
  while (b) swap(a %= b, b);
  return a;
}
const long long INF = 1e9 + 7;
const long long mod = 998244353;
const long long BIG_INF = 1e18 + 7;
const long long N = 1e6 + 7;
const int LOG = 17;
long long n, m, q;
int tab[N];
int root;
vector<vector<int> > G(N);
int label[N];
int rozmiar[N];
void zwieksz_wiekszym(int start, int przodek, int val, int o_ile) {
  if (label[start] > val) label[start] += o_ile;
  for (auto &u : G[start]) {
    if (u != przodek) {
      zwieksz_wiekszym(u, start, val, o_ile);
    }
  }
}
void dfs(int start, int przodek = -1) {
  rozmiar[start] = 1;
  for (auto &u : G[start]) {
    if (u != przodek) {
      dfs(u, start);
      zwieksz_wiekszym(u, start, -1, rozmiar[start] - 1);
      rozmiar[start] += rozmiar[u];
    }
  }
  if (tab[start] > rozmiar[start]) {
    cout << "NO\n";
    exit(0);
  }
  label[start] = tab[start] + 1;
  for (auto &u : G[start]) {
    if (u != przodek) {
      zwieksz_wiekszym(u, start, label[start] - 1, 1);
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < (n); i++) {
    int a;
    cin >> a >> tab[i + 1];
    if (a != 0) {
      G[i + 1].push_back(a);
      G[a].push_back(i + 1);
    } else {
      root = i + 1;
    }
  }
  dfs(root);
  cout << "YES\n";
  for (int i = 1; i <= n; i++) {
    cout << label[i] << ' ';
  }
  cout << '\n';
}
