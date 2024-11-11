#include <bits/stdc++.h>
#pragma GCC optimize("O3")
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
istream &operator>>(istream &os, vector<T> &container) {
  for (auto &u : container) os >> u;
  return os;
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &container) {
  for (auto &u : container) os << u << " ";
  return os;
}
template <class T>
inline T gcd(T a, T b) {
  while (b) swap(a %= b, b);
  return a;
}
const long long INF = 1e9 + 7;
const long long mod = 998244353;
const long long BIG_INF = 1e18 + 7;
const long long N = 1e6 + 7;
const long long T = 1 << 20;
const long double inf = 1e18;
long long n, m, k, q;
int dziel[N];
int dp[N];
int skad[N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  int suma = 0;
  set<int> uzyte;
  for (int i = 1; i <= n; i++) {
    for (int j = i + i; j <= n; j += i) dziel[j]++;
    suma += dziel[i];
    uzyte.insert(i);
  }
  if (suma < k) {
    cout << "No\n";
    exit(0);
  }
  cout << "Yes\n";
  dp[n + 1] = 0;
  skad[n + 1] = n + 1;
  k = suma - k;
  if (k == 0) {
    cout << n << '\n';
    for (auto &u : uzyte) cout << u << ' ';
    exit(0);
  }
  for (int i = n; i >= 1; i--) {
    dp[i] = dziel[i];
    skad[i] = n + 1;
    for (int j = i + 1; j <= min((int)n + 1, i + 7); j++) {
      if (dziel[i] + dp[j] <= k and dziel[i] + dp[j] > dp[i]) {
        dp[i] = dziel[i] + dp[j];
        skad[i] = j;
      }
    }
    if (dp[i] == k) {
      int pom = i;
      while (skad[pom] != pom) {
        uzyte.erase(pom);
        pom = skad[pom];
      }
      cout << (int)(uzyte).size() << '\n';
      for (auto &u : uzyte) cout << u << ' ';
      cout << '\n';
      exit(0);
    }
  }
}
