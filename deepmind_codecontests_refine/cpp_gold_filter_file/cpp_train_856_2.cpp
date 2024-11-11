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
const long long T = 1 << 18;
const long double inf = 1e18;
int n, m, k, l, q;
vector<vector<int> > G(N);
map<pair<int, int>, int> mapa;
int cnt = 0;
int zapytaj(int a, int b) {
  if (mapa.count({a, b})) return mapa[{a, b}];
  if (cnt == 4269) {
    int x = 0;
    while (1) {
      x++;
    }
  }
  cout << "? " << a << ' ' << b << endl;
  cnt++;
  int temp;
  cin >> temp;
  mapa[{a, b}] = mapa[{b, a}] = temp;
  return temp;
}
int zapytaj_o(int poz, vector<int> xd) {
  if (poz == xd[0]) return zapytaj(poz, xd[1]);
  return zapytaj(poz, xd[0]);
}
bool jest_permutacja(vector<int> perm) {
  sort((perm).begin(), (perm).end());
  for (int i = 0; i < (int)(perm).size(); i++)
    if (perm[i] != i) return false;
  return true;
}
int pozostala(vector<int> perm) {
  vector<int> mam(n);
  for (auto &u : perm) mam[u] = 1;
  for (int i = 0; i < n; i++)
    if (!mam[i]) return i;
  assert(false);
}
void solve() {
  vector<vector<int> > zap;
  cin >> n;
  vector<int> A;
  vector<int> B;
  while (1) {
    int a = uniform_int_distribution<long long>(1, n)(rng);
    int b = uniform_int_distribution<long long>(1, n)(rng);
    while (a == b) {
      a = uniform_int_distribution<long long>(1, n)(rng);
      b = uniform_int_distribution<long long>(1, n)(rng);
    }
    int temp = zapytaj(a, b);
    zap.push_back({a, b, temp});
    bool found = 0;
    for (int i = 0; i < (int)(zap).size() - 1; i++)
      if ((zap[i][2] & zap.back()[2]) == 0) {
        A = zap[i];
        B = zap.back();
        found = 1;
        break;
      }
    if (found) break;
  }
  set<int> jeszcze;
  for (int i = 0; i < n; i++) jeszcze.insert(i);
  vector<int> ans;
  for (int j = 1; j < n; j++) {
    int x = zapytaj_o(j, A);
    int ile_ok = 0;
    int kan = -1;
    for (auto &u : jeszcze) {
      if ((u & x) == u) {
        kan = u;
        ile_ok++;
      }
    }
    assert(ile_ok);
    if (ile_ok == 1) {
      ans.push_back(kan);
      jeszcze.erase(kan);
      continue;
    }
    int y = zapytaj_o(j, B);
    int wyn = 0;
    for (int i = 0; i < 30; i++) {
      if ((A[2] & (1 << i)) == 0)
        wyn |= (x & (1 << i));
      else
        wyn |= (y & (1 << i));
    }
    jeszcze.erase(wyn);
    ans.push_back(wyn);
  }
  ans.push_back(pozostala(ans));
  assert(jest_permutacja(ans));
  cout << "! " << ans << endl;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  q = 1;
  while (q--) solve();
}
