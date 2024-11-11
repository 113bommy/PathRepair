#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
template <typename... Args>
void logger(string vars, Args &&...values) {
  cout << vars << " = ";
  string delim = "";
}
inline string toString(int x) {
  string ans = "";
  bool negtive = x < 0;
  x = abs(x);
  while (x) ans.push_back(x % 10 + '0'), x /= 10;
  if (ans.size() == 0) ans = "0";
  if (negtive) ans.push_back('-');
  for (int i = 0; i < ans.size() / 2; i++)
    swap(ans[i], ans[ans.size() - 1 - i]);
  return ans;
}
inline int toInt(const string &str) {
  int ans = 0;
  bool negtive = str[0] == '-';
  for (int i = negtive; i < str.size(); i++) ans = ans * 10 + str[i] - '0';
  if (negtive) ans *= -1;
  return ans;
}
inline int gcd(int x, int y) { return x ? gcd(y % x, x) : y; }
long long exgcd(long long a, long long b, long long &x, long long &y) {
  long long d = a;
  if (b == 0)
    x = 1, y = 0;
  else {
    d = exgcd(b, a % b, y, x), y -= a / b * x;
  }
  return d;
}
const int mod = 998244353;
inline int read() {
  int ans = 0;
  char last = ' ', ch = getchar();
  while (!(ch >= '0' && ch <= '9')) last = ch, ch = getchar();
  while (ch >= '0' && ch <= '9')
    ans = (ans << 3) + (ans << 1) + ch - '0', ch = getchar();
  return ans;
}
inline int QPow(long long a, long long b) {
  long long ans = 1;
  if (b < 0) return 0;
  while (b) {
    if (b & 1) ans = ans * a;
    a = a * a;
    b >>= 1;
  }
  return ans;
}
inline int QPow(long long a, long long b, const int &mod) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}
const double PI = 3.141592653589793115997963468544185161590576171875;
const double e = 2.718281828459045;
void ask(int x) {
  cout << '?' << ' ' << x << endl;
  cout.flush();
  ;
}
void decide(int x) {
  cout << "! " << x << endl;
  cout.flush();
  ;
}
short _min(short a, short b) { return a < b ? a : b; }
const int inf = (long long)1 << 60;
const int inf2 = 10000;
const double eps = 1e-10;
int db_cmp(double x, double y) {
  if (fabs(x - y) < eps) return 0;
  if (x > y) return 1;
  return -1;
}
const int maxn = 2002;
int arr[maxn];
int dp[maxn][maxn];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t, n, k;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    dp[1][1] = 0;
    dp[1][0] = arr[1] == 1;
    for (int i = 2; i <= n; i++) {
      for (int j = 1; j <= i; j++) {
        dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j] + (arr[i] == i - j));
      }
      dp[i][0] = (arr[i] == i) + dp[i - 1][0];
      dp[i][i] = 0;
    }
    int ans = -1;
    for (int i = 1; i <= n; i++)
      if (dp[n][i] >= k) {
        ans = i;
        break;
      }
    cout << ans << '\n';
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) dp[i][j] = 0;
  }
  return 0;
}
