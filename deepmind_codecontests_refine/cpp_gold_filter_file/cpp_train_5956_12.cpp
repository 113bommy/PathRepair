#include <bits/stdc++.h>
using namespace std;
template <class T>
void dbs(string str, T t) {
  cerr << str << " : " << t << "\n";
}
template <class T, class... S>
void dbs(string str, T t, S... s) {
  int idx = str.find(',');
  cerr << str.substr(0, idx) << " : " << t << ",";
  dbs(str.substr(idx + 1), s...);
}
template <class S, class T>
ostream &operator<<(ostream &os, const pair<S, T> &p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
template <class T>
void debug(T a, T b) {
  cerr << "[";
  for (T i = a; i != b; ++i) {
    if (i != a) cerr << ", ";
    cerr << *i;
  }
  cerr << "]\n";
}
const int mod = 998244353;
const int N = 200200;
inline int mul(int a, int b) { return (long long)a * b % mod; }
inline void add(int &a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}
inline int powMod(int x, int n) {
  int ret = 1;
  while (n > 0) {
    if (n & 1) {
      ret = mul(ret, x);
    }
    n >>= 1;
    x = mul(x, x);
  }
  return ret;
}
int fact[N], inv[N];
inline int binomial(int n, int r) {
  if (r < 0 or r > n) {
    return 0;
  }
  int ret = mul(fact[n], inv[r]);
  return mul(ret, inv[n - r]);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  fact[0] = 1;
  for (int i = 1; i < N; ++i) {
    fact[i] = mul(fact[i - 1], i);
  }
  inv[N - 1] = powMod(fact[N - 1], mod - 2);
  for (int i = N - 2; i >= 0; --i) {
    inv[i] = mul(inv[i + 1], i + 1);
  }
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int same = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == (a[(i + n - 1) % n])) {
      ++same;
    }
  }
  int diff = n - same;
  int ways = 0;
  for (int i = 1; i <= diff; ++i) {
    int sum = 0;
    for (int j = 0; j < i and i + j <= diff; ++j) {
      add(sum, mul(binomial(diff - i, j), powMod(k - 2, diff - i - j)));
    }
    add(ways, mul(binomial(diff, i), sum));
  }
  int ways2 = powMod(k, same);
  cout << mul(ways, ways2) << "\n";
  return 0;
}
