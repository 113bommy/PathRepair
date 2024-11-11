#include <bits/stdc++.h>
using namespace std;
const int N = 500500;
const int mod = 1e9 + 7;
const long long inf = 1e18;
int q[N * 10 + 1];
inline int bin(int x, int k, int mod) {
  int res = 1;
  while (k) {
    if (k & 1) res = res * 1ll * x % mod;
    x = x * 1ll * x % mod;
    k >>= 1;
  }
  return res;
}
long long u, v, p;
map<int, int> wu, wv, pu, pv;
inline void printu(int x) {
  vector<int> res;
  while (x != u) {
    int type = pu[x];
    res.push_back(type);
    if (type == 1)
      x = (x + p - 1) % p;
    else if (type == 2)
      x = (x + 1) % p;
    else
      x = bin(x, p - 2, p);
  }
  reverse(res.begin(), res.end());
  for (int x : res) cout << x << ' ';
}
inline void printv(int x) {
  vector<int> res;
  while (x != v) {
    int type = pv[x];
    res.push_back(type);
    if (type == 1)
      x = (x + 1) % p;
    else if (type == 2)
      x = (x + p - 1) % p;
    else
      x = bin(x, p - 2, p);
  }
  for (int x : res) cout << x << ' ';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> u >> v >> p;
  int qs = 0, qt = 0;
  q[qt++] = u;
  while (qs < qt && qt < 5e5) {
    int x = q[qs++];
    int res = wu[x];
    int tox = (x + 1) % p;
    if (!wu.count(tox)) {
      wu[tox] = res + 1;
      pu[tox] = 1;
      q[qt++] = tox;
    }
    tox = (x + p - 1) % p;
    if (!wu.count(tox)) {
      wu[tox] = res + 1;
      pu[tox] = 2;
      q[qt++] = tox;
    }
    tox = bin(x, p - 2, p);
    if (!wu.count(tox)) {
      wu[tox] = res + 1;
      pu[tox] = 3;
      q[qt++] = tox;
    }
  }
  qs = 0, qt = 0;
  q[qt++] = v;
  while (qs < qt && qt < 5e5) {
    int x = q[qs++];
    int res = wv[x];
    auto it = wu.lower_bound(x);
    if (it != wu.end() && (it->second + abs(it->first - x) + res) < 200) {
      cout << it->second + abs(it->first - x) + res << '\n';
      printu(it->first);
      for (long long i = 1; i <= abs(it->first) - x; ++i) cout << 1 << ' ';
      printv(x);
      return 0;
    }
    if (it != wu.begin()) {
      it--;
      if (it != wu.end() && (it->second + abs(it->first - x) + res) < 200) {
        cout << it->second + abs(it->first - x) + res << '\n';
        printu(it->first);
        for (long long i = 1; i <= abs(it->first - x); ++i) cout << 2 << ' ';
        printv(x);
        return 0;
      }
    }
    int tox = (x + 1) % p;
    if (!wv.count(tox)) {
      wv[tox] = res + 1;
      pv[tox] = 2;
      q[qt++] = tox;
    }
    tox = (x + p - 1) % p;
    if (!wv.count(tox)) {
      wv[tox] = res + 1;
      pv[tox] = 1;
      q[qt++] = tox;
    }
    tox = bin(x, p - 2, p);
    if (!wv.count(tox)) {
      wv[tox] = res + 1;
      pv[tox] = 3;
      q[qt++] = tox;
    }
  }
  return 0;
}
