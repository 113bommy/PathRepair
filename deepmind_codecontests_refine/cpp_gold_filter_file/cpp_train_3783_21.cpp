#include <bits/stdc++.h>
using namespace std;
inline string toString(int x) {
  string ans = "";
  bool negtive = x < 0;
  while (x) ans.push_back(x % 10 + '0'), x /= 10;
  if (ans.size() == 0) ans = "0";
  if (negtive) ans.push_back('-');
  for (int i = 0; i < ans.size() / 2; i++)
    swap(ans[i], ans[ans.size() - 1 - i]);
  return ans;
}
inline int toInt(const string& str) {
  int ans = 0;
  bool negtive = str[0] == '-';
  for (int i = negtive; i < str.size(); i++) ans = ans * 10 + str[i] - '0';
  if (negtive) ans *= -1;
  return ans;
}
inline int gcd(int x, int y) { return x ? gcd(y % x, x) : y; }
const int mod = 1e9 + 7;
inline signed rd() {
  signed ans = 0;
  char last = ' ', ch = getchar();
  while (!(ch >= '0' && ch <= '9')) last = ch, ch = getchar();
  while (ch >= '0' && ch <= '9')
    ans = (ans << 3) + (ans << 1) + ch - '0', ch = getchar();
  return ans;
}
inline int QPow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}
inline int QPow(int a, int b, const int& mod) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}
const long double PI = 3.141592653589793115997963468544185161590576171875;
const int maxn = 5005;
const int inf = 1000000000;
int filled[maxn][2];
int state[maxn][2];
int last[maxn][2][2];
signed dp[502][502];
string a, b;
int n, m;
int Max = 0;
int arr[maxn];
void solve(const string& a, int len, int c) {
  int cur = 0;
  bool _0 = 0, _1 = 0;
  for (int i = len; i >= 1; i--) {
    if (a[i] == '0')
      _0 = 1;
    else
      _1 = 1;
    if (_0 && _1) cur++, _0 = 0, _1 = 0;
    filled[i][c] = cur;
    if (_0)
      state[i][c] = 0;
    else if (_1)
      state[i][c] = 1;
    else
      state[i][c] = -1;
  }
  last[len][c][0] = last[len][c][1] = -1;
  for (int i = len - 1; i >= 0; i--) {
    last[i][c][a[i + 1] - '0'] = i + 1;
    last[i][c]['1' - a[i + 1] + '0'] = last[i + 1][c]['1' - a[i + 1] + '0'];
  }
}
void getDp() {
  for (int i = n; i >= 1; i--) {
    for (int j = m; j >= 1; j--) {
      dp[i][j] = min(filled[i][0], filled[i][1]);
      if (filled[i][0] == filled[i][1])
        dp[i][j] += state[i][0] == 1 && state[j][1] == 0 ||
                    state[i][0] == 0 && state[j][1] == 1;
    }
  }
}
string solve2() {
  solve(a, n, 0), solve(b, m, 1);
  string ans = "";
  getDp();
  Max = dp[1][1];
  int p1 = 0, p2 = 0;
  for (int j = 1; j <= Max; j++) {
    int cur = -1;
    if (dp[last[p1][0][0] + 1][last[p2][1][0] + 1] < Max - j) {
      cur = 0;
      p1 = last[p1][0][0];
      p2 = last[p2][1][0];
    } else if (dp[last[p1][0][1] + 1][last[p2][1][1] + 1] < Max - j) {
      cur = 1;
      p1 = last[p1][0][1];
      p2 = last[p2][1][1];
    }
    if (cur == -1) break;
    ans.push_back('0' + cur);
  }
  if (ans.size()) return ans;
  return ans;
}
void process() {
  a.clear(), b.clear();
  n = rand() % 11, m = rand() % 11;
  n++, m++;
  for (int i = 1; i <= n; i++) a.push_back((rand() % 2) + '0');
  for (int i = 1; i <= m; i++) b.push_back((rand() % 2) + '0');
  a = " " + a, b = " " + b;
}
bool check(string p, const string& s, int len) {
  if (p.size() == 0) return 0;
  int ptr = 1;
  for (int i = 0; i < p.size(); i++) {
    while (ptr <= len && s[ptr] != p[i]) ptr++;
    if (ptr > len) return 1;
    ptr++;
  }
  return 0;
}
signed grid[502][502];
signed rs[502][502], cs[502][502];
signed tmpDp[502][502];
signed pre[502][502];
signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int p, t;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> grid[i][j];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cs[i][j] = cs[i][j - 1] + grid[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) pre[i][j] = cs[i][j] + pre[i - 1][j];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      dp[i][j] = grid[i][j];
    }
  }
  signed ans = -inf;
  for (int i = 3; i <= n; i += 2) {
    for (int j = 1; j <= n - i + 1; j++) {
      for (int k = 1; k <= m - i + 1; k++) {
        tmpDp[j][k] = pre[j + i - 1][k + i - 1] - pre[j - 1][k + i - 1] -
                      pre[j + i - 1][k - 1] + pre[j - 1][k - 1] -
                      dp[j + 1][k + 1] - grid[j + 1][k];
        ans = max(ans, tmpDp[j][k]);
      }
    }
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) dp[i][j] = -inf;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) dp[i][j] = tmpDp[i][j];
  }
  cout << ans << endl;
  return 0;
}
