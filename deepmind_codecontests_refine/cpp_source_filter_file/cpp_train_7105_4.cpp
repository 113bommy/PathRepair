#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
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
  return abs(a);
}
const long long INF = 1e9 + 7;
const long long mod = 998244353;
const long long BIG_INF = 1e18 + 7;
const long long N = 1e6 + 7;
const long long T = 1 << 20;
const long double inf = 1e18;
long long n, m, q, k, r;
bool sorted(vector<int> tab) {
  for (int i = 1; i < (int)(tab).size(); i++)
    if (tab[i] < tab[i - 1]) return false;
  return true;
}
bool cool(vector<int> tab) {
  bool byly_przed = 0;
  bool kon = 0;
  for (int i = 0; i < (n); i++) {
    if (tab[i] != i + 1) {
      if (kon) return false;
      byly_przed = 1;
    } else {
      if (byly_przed) kon = 1;
    }
  }
  return true;
}
void solve() {
  cin >> n;
  vector<int> tab(n);
  cin >> tab;
  if (n == 1) {
    cout << tab[0] << '\n';
    return;
  }
  for (int i = 0; i < (n * 2); i++) tab.push_back(tab[i]);
  vector<long long> pref(N);
  long long temp = 0;
  int pom = (n - 3) / 2;
  for (int i = 0; pom; i += 2, pom--) temp += tab[i];
  pref[0] = temp;
  for (int i = 2; i < n * 2; i += 2) {
    temp -= tab[i - 2];
    temp += tab[i + n - 1];
    pref[i] = temp;
  }
  temp = 0;
  pom = (n - 3) / 2;
  for (int i = 1; pom; i += 2, pom--) temp += tab[i];
  pref[1] = temp;
  for (int i = 3; i < n * 2; i += 2) {
    temp -= tab[i - 2];
    temp += tab[i + n - 1];
    pref[i] = temp;
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) setmax(ans, pref[i + 3] + tab[i] + tab[i + 1]);
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  q = 1;
  for (int i = 1; i <= q; i++) solve();
}
