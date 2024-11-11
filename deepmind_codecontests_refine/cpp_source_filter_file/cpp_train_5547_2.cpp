#include <bits/stdc++.h>
#pragma GCC optimize(3, "Ofast", "inline")
const double eps = 1e-7;
const int maxn = 1e5 + 10;
const int prime[15] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
const int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
int spgcd(int a, int b) {
  while (b ^= a ^= b ^= a %= b)
    ;
  return a;
}
inline int mul(int a, int b, int p) { return (long long)a * b % p; }
template <typename T>
void scan(T &x) {
  x = 0;
  bool _ = 0;
  T c = getchar();
  _ = c == 45;
  c = _ ? getchar() : c;
  while (c < 48 || c > 57) c = getchar();
  for (; c < 48 || c > 57; c = getchar())
    ;
  for (; c > 47 && c < 58; c = getchar()) x = (x << 3) + (x << 1) + (c & 15);
  x = _ ? -x : x;
}
template <typename T>
void printn(T n) {
  bool _ = 0;
  _ = n < 0;
  n = _ ? -n : n;
  char snum[65];
  int i = 0;
  do {
    snum[i++] = n % 10 + 48;
    n /= 10;
  } while (n);
  --i;
  if (_) putchar(45);
  while (i >= 0) putchar(snum[i--]);
}
template <typename First, typename... Ints>
void scan(First &arg, Ints &...rest) {
  scan(arg);
  scan(rest...);
}
template <typename T>
void print(T n) {
  printn(n);
  putchar(10);
}
template <typename First, typename... Ints>
void print(First arg, Ints... rest) {
  printn(arg);
  putchar(32);
  print(rest...);
}
using namespace std;
int x[maxn], y[maxn], t[maxn];
int dp[maxn];
void solve() {
  int n, k;
  int ans = 0;
  cin >> k >> n;
  for (int i = 1; i <= n; i++) {
    cin >> t[i] >> x[i] >> y[i];
    dp[i] = -0x7f7f7f7f;
  }
  x[0] = y[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = max(0, i - 2 * k - 10); j < i; j++) {
      if (abs(x[i] - x[j]) + abs(y[i] - y[j]) <= t[i] - t[j]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
    ans = max(dp[i], ans);
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  solve();
  return 0;
}
