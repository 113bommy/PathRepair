#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e6 + 100;
const long long MaxN = 1e5 + 100;
const long long mod = 1e9 + 21;
const double PI =
    3.14159265358979323846264338327950288419716939937510582097494459230;
inline long long fast_expo(long long base, long long power,
                           long long modulo = mod) {
  long long x = base, cnt = power, ans = 1;
  while (cnt) {
    if (cnt & 1) ans = (ans * x) % mod;
    x = (x * x) % mod;
    cnt >>= 1;
  }
  long long tmp = ans;
  return tmp;
}
inline long long fib(long long n, long long a = 1, long long b = 1,
                     long long c = 1, long long d = 0, long long acca = 0,
                     long long accb = 1, long long m = mod) {
  if (n == 0) return acca;
  if (n & 1)
    return fib(n / 2, ((a * a) % m + (b * c) % m) % m,
               ((a * b) % m + (b * d) % m) % m, (c * (a + d) % m) % m,
               ((c * b) % m + (d * d) % m) % m,
               ((a * acca) % m + (b * accb) % m) % m,
               ((c * acca) % m + (d * accb) % m) % m, m);
  else
    return fib(n / 2, ((a * a) % m + (b * c) % m) % m,
               ((a * b) % m + (b * d) % m) % m, (c * (a + d) % m) % m,
               ((c * b) % m + (d * d) % m) % m, acca, accb, m);
}
struct base {
  double x, y;
  base() {
    x = 0;
    y = 0;
  }
  base(double a) {
    x = a;
    y = 0;
  }
  base(double a, double b) {
    x = a;
    y = b;
  }
  base conj() { return base(x, -y); }
  base operator=(const base &o) {
    x = o.x;
    y = o.y;
    return *this;
  }
  base operator+(const base &o) const { return base(x + o.x, y + o.y); }
  base operator-(const base &o) const { return base(x - o.x, y - o.y); }
  base operator*(const base &o) const {
    return base(x * o.x - y * o.y, y * o.x + x * o.y);
  }
  base operator*(const double num) const { return base(x * num, y * num); }
  base operator/(const double num) const { return base(x / num, y / num); }
};
char arr[1050][1050];
long long dp[1050][1050], vis[2][1050][1050], val[1050][1050], used[maxn];
long long tot = 0, cnt = 0;
void dfs(long long i, long long j, long long n, long long m, long long idx) {
  if (i < 0 || j < 0 || i >= n || j >= m) return;
  if (vis[idx][i][j] || arr[i][j] == '*') return;
  vis[idx][i][j] = 1;
  if (idx) {
    dp[i][j] = tot;
    val[i][j] = cnt;
  } else
    tot++;
  dfs(i, j + 1, n, m, idx);
  dfs(i, j - 1, n, m, idx);
  dfs(i - 1, j, n, m, idx);
  dfs(i + 1, j, n, m, idx);
}
signed main() {
  long long n, m;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  for (long long i = 0; i < maxn; i++) used[i] = 0;
  for (long long i = 0; i < n; i++)
    for (long long j = 0; j < m; j++) {
      cin >> arr[i][j];
      dp[i][j] = 0;
      for (long long k = 0; k < 2; k++) {
        vis[k][i][j] = 0;
      }
    }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (vis[0][i][j]) continue;
      tot = 0;
      dfs(i, j, n, m, 0);
      dfs(i, j, n, m, 1);
      cnt++;
    }
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (arr[i][j] == '.')
        cout << arr[i][j];
      else {
        long long s = 1;
        if (i != 0) {
          s += dp[i - 1][j];
          used[val[i - 1][j]] = 1;
        }
        if (j != 0 && used[val[i][j - 1]] == 0) {
          s += dp[i][j - 1];
          used[val[i][j - 1]] = 1;
        }
        if (i != n - 1 && used[val[i + 1][j]] == 0) {
          s += dp[i + 1][j];
          used[val[i + 1][j]] = 1;
        }
        if (j != m - 1 && used[val[i][j + 1]] == 0) {
          s += dp[i][j + 1];
          used[val[i][j + 1]] = 1;
        }
        if (i != 0) used[val[i - 1][j]] = 0;
        if (j != 0) used[val[i][j - 1]] = 0;
        if (i != n - 1) used[val[i + 1][j]] = 0;
        if (j != m - 1) used[val[i][j + 1]] = 0;
        cout << s;
      }
    }
    cout << "\n";
  }
}
