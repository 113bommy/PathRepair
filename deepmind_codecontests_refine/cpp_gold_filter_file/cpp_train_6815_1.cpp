#include <bits/stdc++.h>
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
const long long T = 1 << 18;
const long long INF = 1e9 + 7;
const long long mod = 998244353;
const long long BIG_INF = 1e18 + 7;
const long long N = 1e6 + 7;
const int LOG = 21;
long long n, m, k;
string w;
int potB[N];
int pref[N];
int suf[N];
void prep() {
  potB[0] = 1 % m;
  for (int i = 1; i < N; i++) potB[i] = (potB[i - 1] * 10) % m;
  for (int i = 1; i <= (int)(w).size(); i++)
    pref[i] = (pref[i - 1] * 10 + (w[i - 1] - '0')) % n;
  for (int i = (int)(w).size(); i >= 1; i--)
    suf[i] = (suf[i + 1] + (potB[(int)(w).size() - i] * (w[i - 1] - '0'))) % m;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> w >> n >> m;
  prep();
  for (int i = 1; i < (int)(w).size(); i++)
    if (pref[i] == 0 && suf[i + 1] == 0 && w[i] != '0') {
      cout << "YES\n"
           << w.substr(0, i) << '\n'
           << w.substr(i, (int)(w).size() - i) << '\n';
      exit(0);
    }
  cout << "NO\n";
}
