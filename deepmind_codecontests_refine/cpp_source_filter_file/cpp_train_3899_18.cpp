#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
const long long INF = 1e18;
template <typename T1, typename T2>
inline bool chmin(T1& a, T2 b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename T1, typename T2>
inline bool chmax(T1& a, T2 b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename T>
T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <typename T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
template <typename T>
T pow(T a, int b) {
  return b ? pow(a * a, b / 2) * (b % 2 ? a : 1) : 1;
}
const int mod = 1000000007;
long long modpow(long long a, int b) {
  return b ? modpow(a * a % mod, b / 2) * (b % 2 ? a : 1) % mod : 1;
}
template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  for (int i = 0; i < ((int)v.size()); ++i) {
    if (i) os << " ";
    os << v[i];
  }
  return os;
}
template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
  os << p.first << " " << p.second;
  return os;
}
template <class T>
inline void add(T& a, int b) {
  a += b;
  if (a >= mod) a - mod;
}
void solve();
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  T = 1;
  while (T--) {
    solve();
  }
}
void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> table(3005);
  for (int i = 0; i < (n); ++i) {
    int x, y;
    cin >> x >> y;
    table[x] += y;
  }
  int ans = 0, prev = 0;
  for (int i = 0; i < (3001); ++i) {
    int now = table[i];
    if (prev + now <= m) {
      ans += prev + now;
      prev = 0;
    } else {
      ans += m;
      prev = now - max(0, m - prev);
    }
  }
  cout << ans << endl;
}
