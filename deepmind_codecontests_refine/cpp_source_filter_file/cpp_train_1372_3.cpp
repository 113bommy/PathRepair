#include <bits/stdc++.h>
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
inline T sub(T a, T b, T mod) {
  return ((a % mod - b % mod) + mod) % mod;
}
template <class T>
inline T add(T a, T b, T mod) {
  return (a % mod + b % mod) % mod;
}
template <class T>
inline T mult(T a, T b, T mod) {
  return ((a % mod * b % mod) + mod) % mod;
}
template <class T>
inline T mult(vector<T> vec, T mod) {
  T ret = 1;
  for (int i = 0; i < (int)(vec).size(); i++) ret = (ret * vec[i]) % mod;
  return ret;
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
long double PI = acos(-1);
long double eps = 1e-11;
const long long T = 1 << 19;
const long long INF = 1e9 + 7;
const long long mod = 998244353;
const long long BIG_INF = 1e18 + 7;
const long long N = 1e6 + 7;
long long n, m, k;
long long licznik;
int ost[N];
int czas = 0;
int tree[T * 2];
int ask(int pocz, int kon) {
  pocz += T - 1;
  kon += T + 1;
  int ret = 0;
  while (pocz / 2 != kon / 2) {
    if (!(pocz & 1)) setmax(ret, tree[pocz + 1]);
    if (kon & 1) setmax(ret, tree[kon - 1]);
    pocz /= 2;
    kon /= 2;
  }
  return ret;
}
void ustaw(int poz, int val) {
  poz += T;
  tree[poz] = val;
  poz /= 2;
  while (poz) {
    tree[poz] = max(tree[poz * 2], tree[poz * 2 + 1]);
    poz /= 2;
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n;
  vector<int> tab(n);
  cin >> tab;
  int q;
  cin >> q;
  for (int i = 1; i <= q; i++) {
    int a;
    cin >> a;
    int b;
    cin >> b;
    if (a == 1) {
      int c;
      cin >> c;
      b--;
      tab[b] = c;
      ost[b] = i;
    } else {
      ustaw(i, b);
    }
  }
  for (int i = 0; i < n; i++) {
    cout << max(tab[i], ask(max(ost[i], 1), n + 1)) << ' ';
  }
}
