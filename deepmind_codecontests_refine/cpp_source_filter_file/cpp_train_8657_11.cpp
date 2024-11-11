#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
clock_t START;
inline long double TIME() {
  return (long double)(clock() - START) / CLOCKS_PER_SEC;
}
void SHOW() {
  cout << fixed << setprecision(10);
  cout << TIME() << " SECONDS FROM START\n";
}
long double TL = 2.0;
long long calls = 0;
inline bool IS() {
  if (++calls == 1000) {
    calls = 0;
    if (TL - TIME() < 0.1) return true;
  }
  return false;
}
template <typename T1, typename T2>
inline bool amin(T1 &a, T2 b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T1, typename T2>
inline bool amax(T1 &a, T2 b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, pair<T1, T2> &p) {
  os << p.first << ' ' << p.second;
  return os;
}
template <typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) {
  is >> p.first >> p.second;
  return is;
}
template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
  for (auto &u : v) is >> u;
  return is;
}
template <typename T>
ostream &operator<<(ostream &os, vector<T> &v) {
  for (auto &u : v) os << u << ' ';
  return os;
}
long long hash_mod[4] = {1000000007, 998244353, 1000000009, 999999937},
          mod = hash_mod[rnd() % 4];
long long hash_pows[4] = {179, 239, 1007, 2003}, P = hash_pows[rnd() % 4];
long long binpow(long long first, long long p) {
  long long res = 1;
  while (p) {
    if (p % 2) res = (res * first) % mod;
    first = (first * first) % mod;
    p /= 2;
  }
  return res;
}
const long long N = 1e6 + 7, NS = 2e3 + 7, lg = 20, sq = 550, inf = 2e9 + 7,
                SM = 1e2 + 7;
const long double eps = 1e-9;
template <typename T>
bool check(T from, T to) {
  long long lst = -inf, d = -inf;
  for (auto it = from; it != to; it++) {
    if (lst != -inf) {
      if (d != -inf && d != *it - lst) {
        return 0;
      }
      d = *it - lst;
    }
    lst = *it;
  }
  return 1;
}
void solve() {
  long long n;
  cin >> n;
  if (n == 2) {
    cout << 1;
    return;
  }
  vector<long long> a(n);
  cin >> a;
  map<long long, long long> pos;
  for (long long i = 0; i < n; i++) pos[a[i]] = i;
  sort((a).begin(), (a).end());
  if (a.front() == a.back()) {
    cout << 1;
    return;
  }
  if (check(++a.begin(), a.end())) {
    cout << pos[a.front()] + 1;
    return;
  }
  if (check(a.begin(), --a.end())) {
    cout << pos[a.back()] + 1;
    return;
  }
  long long d = (a.back() - a.front()) / (n - 2);
  if (a.back() - a.front() != (n - 2) * d) {
    cout << -1;
    return;
  }
  long long c = a.front();
  map<long long, bool> used;
  vector<long long> wrong;
  for (long long i = 0; i < n; i++) {
    long long e = (a[i] - c) / d;
    if (used.count(e) || e >= n) wrong.push_back(i);
    used[e] = 1;
  }
  if (wrong.size() == 0) wrong.push_back(0);
  if (wrong.size() > 1)
    cout << -1;
  else
    cout << pos[wrong[0]] + 1;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
