#include <bits/stdc++.h>
using namespace std;
namespace MATH_CAL {
const int mod = 1e9 + 9;
inline long long add(long long a, long long b) {
  return a + b >= mod ? a + b - mod : a + b;
}
inline long long sub(long long a, long long b) {
  return a - b < 0 ? a - b + mod : a - b;
}
inline long long mul(long long a, long long b) {
  return (long long)a * b % mod;
}
inline void Add(long long &a, long long b) { (a += b) >= mod ? a -= mod : 0; }
inline void Sub(long long &a, long long b) { (a -= b) < 0 ? a += mod : 0; }
inline long long qpow(long long x, long long n) {
  long long r = 1;
  for (; n; n /= 2, x = mul(x, x))
    if (n & 1) r = mul(r, x);
  return r;
}
inline long long mod_inv(long long x) { return qpow(x, mod - 2); }
inline long long gcd(long long a, long long b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
inline long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
}  // namespace MATH_CAL
using namespace MATH_CAL;
const int N = 1e6 + 5;
const int M = 1e3 + 5;
long long pref_col[N];
long long pref_row[N];
int a[M][M];
long long col[M];
long long row[M];
void solve() {
  int n, m, k, p;
  cin >> n >> m >> k >> p;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int x;
      cin >> x;
      a[i][j] = x;
      col[j] += x;
      row[i] += x;
    }
  }
  priority_queue<long long> q;
  for (int i = 0; i < n; i++) {
    q.push(row[i]);
  }
  for (int i = 1; i <= k; i++) {
    if (i == 1) {
      pref_row[i] = q.top();
    } else {
      pref_row[i] = pref_row[i - 1] + q.top();
    }
    long long was = q.top();
    q.pop();
    q.push(was - n * p);
  }
  while (!q.empty()) q.pop();
  for (int i = 0; i < m; i++) {
    q.push(col[i]);
  }
  for (int i = 1; i <= k; i++) {
    if (i == 1) {
      pref_col[i] = q.top();
    } else {
      pref_col[i] = pref_col[i - 1] + q.top();
    }
    long long was = q.top();
    q.pop();
    q.push(was - m * p);
  }
  while (!q.empty()) q.pop();
  long long res = numeric_limits<long long>::min();
  for (int i = 0; i <= k; i++) {
    int from_rows = i;
    int from_cols = k - i;
    res = max(res, pref_row[from_rows] + pref_col[from_cols] -
                       from_cols * 1ll * p * from_rows);
  }
  cout << res << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
