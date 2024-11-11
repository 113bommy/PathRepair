#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
template <typename T>
T sqr(T a) {
  return a * a;
}
template <typename T>
int sign(T a) {
  if (a == 0) return 0;
  return (a > 0 ? 1 : -1);
}
template <typename T>
bool uax(T& a, const T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
bool uin(T& a, const T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T1, typename T2>
istream& operator>>(istream& in, pair<T1, T2>& p) {
  in >> p.first >> p.second;
  return in;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& out, pair<T1, T2>& p) {
  out << p.first << ' ' << p.second;
  return out;
}
mt19937_64 rnd(0);
const int LOG = 22;
const int N = (int)5e5 + 7;
const int MAXN = (int)2e5 + 7;
const int MOD = (int)1e9 + 7;
const int INF = (int)2e9 + 7;
const int CONST = 450;
const long long LINF = (int64_t)1e18;
const long double PI = 3.1415926535897932384626433832795;
const long double EPS = 1;
struct Bitset {
  unsigned long long arr[MAXN] = {};
  int len = 0;
  Bitset(){};
  void resize(int n) { len = (n + 63) / 64; }
  void set(int pos) { arr[pos >> 6] |= 1ULL << (pos & ((1 << 6) - 1)); }
  bool get(int pos) {
    return (arr[pos >> 6] & (1ULL << (pos & ((1 << 6) - 1)))) > 0;
  }
  void operator|=(const Bitset& b) {
    for (int i = 0; i < b.len; i++) arr[i] |= b.arr[i];
  }
  void operator<<=(int shift) {
    if (shift % 64 == 0) {
      int sh = shift / 64;
      for (int i = len - sh - 1; i >= 0; i--) {
        arr[i + sh] = arr[i];
        arr[i] = 0;
      }
      return;
    }
    int sh = shift / 64;
    int pos = len - sh - 1;
    int right = shift % 64, left = 64 - right;
    fill(arr + pos + 1, arr + len, 0);
    unsigned long long val = arr[pos] << right;
    arr[pos] = 0, arr[pos + sh] = val;
    for (int i = pos - 1; i >= 0; i--) {
      unsigned long long v1 = arr[i] << right, v2 = arr[i] >> left;
      arr[i] = 0;
      arr[i + sh] |= v1;
      arr[i + sh + 1] |= v2;
    }
  }
  void print() {
    vector<int> ones;
    for (int i = 0; i < len; i++) {
      for (int j = 0; j < 64; j++) {
        if (get((i << 6) + j)) ones.push_back((i << 6) + j);
      }
    }
    for (int x : ones) cout << x << ' ';
    cout << "\n";
  }
};
int n, x, y, md[N], ans[N];
Bitset cur, can;
bool pr[N];
void sieve() {
  fill(pr + 2, pr + N, true);
  for (int i = 2; i < N; i++) {
    if (!pr[i]) continue;
    md[i] = i;
    for (long long j = 1LL * i * i; j < N; j += i) pr[j] = false, md[j] = i;
  }
}
void solve() {
  cin >> n >> x >> y;
  can.resize(x);
  int a = 0, b = 0;
  for (int i = 0; i <= n; i++) {
    cin >> b;
    if (i == 0) continue;
    cur.resize(b);
    cur <<= b - a;
    cur.set(b - a);
    can |= cur;
    a = b;
  }
  fill(ans, ans + N, -1);
  for (int i = 0; i <= x; i++) {
    if (can.get(i)) ans[i + y] = i + y;
  }
  sieve();
  for (int i = 2; i < N; i++) {
    int x = i;
    while (x > 1) {
      int p = md[x];
      uax(ans[i], ans[i / p]);
      while (x % p == 0) x /= p;
    }
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int lap;
    cin >> lap;
    lap /= 2;
    cout << max(2 * ans[lap], -1) << ' ';
  }
}
int main() {
  double start = clock();
  cout << fixed << setprecision(20);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  rnd.seed(time(0));
  int t = 1;
  for (int i = 0; i < t; i++) {
    solve();
  }
}
