#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vll = vector<long long int>;
template <class T>
int sgn(T x) {
  return (x > 0) - (x < 0);
}
template <typename T>
inline void read(vector<T>& v) {
  for (T& i : v) cin >> i;
}
long long int euclid(long long int a, long long int b, long long int& x,
                     long long int& y) {
  if (!b) return x = 1, y = 0, a;
  long long int d = euclid(b, a % b, y, x);
  return y -= a / b * x, d;
}
long long int crt(long long int a, long long int m, long long int b,
                  long long int n) {
  if (n > m) swap(a, b), swap(m, n);
  long long int x, y, g = euclid(m, n, x, y);
  if ((a - b) % g != 0) {
    return -1;
  }
  x = (b - a) % n * x % n / g * m + a;
  return x < 0 ? x + m * n / g : x;
}
bool solve(int caseN) {
  int n, k;
  cin >> n >> k;
  vi a(n);
  read(a);
  vi rev(n);
  for (int i = 0; i < n; i++) {
    rev[a[i] - 1] = i;
  }
  vi b(k);
  read(b);
  set<int> will;
  for (int i : b) {
    will.insert(i);
  }
  set<int> has;
  for (int i = 0; i < n; i++) {
    has.insert(i);
  }
  long long int tot = 1;
  for (int i = 0; i < k; i++) {
    will.erase(b[i]);
    vi adj;
    auto next = has.upper_bound(rev[b[i] - 1]);
    if (next != has.end()) {
      adj.push_back(*next);
    }
    auto lo = has.lower_bound(rev[b[i] - 1]);
    if (lo != has.begin()) {
      lo--;
      adj.push_back(*lo);
    }
    vi inB;
    for (int j : adj) {
      if (will.count(a[j])) {
        inB.push_back(j);
      }
    }
    if ((int)inB.size() == (int)adj.size()) {
      cout << "0\n";
      return false;
    }
    for (int j : adj) {
      if (!will.count(a[j])) {
        has.erase(j);
      }
    }
    tot = (tot * ((int)adj.size() - (int)inB.size())) % 998244353;
  }
  cout << tot << "\n";
  return false;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(20);
  cout << fixed;
  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i) solve(i);
  cout.flush();
  return 0;
}
