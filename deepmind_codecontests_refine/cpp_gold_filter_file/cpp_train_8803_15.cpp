#include <bits/stdc++.h>
using namespace std;
struct io {
  char buf[1 << 23 | 3], *s;
  int f;
  io() { f = 0, buf[fread(s = buf, 1, 1 << 23, stdin)] = '\n'; }
  io& operator>>(int& x) {
    for (x = f = 0; !isdigit(*s); ++s) f |= *s == '-';
    while (isdigit(*s)) x = x * 10 + (*s++ ^ 48);
    return x = f ? -x : x, *this;
  }
};
const int maxn = 5e3 + 35;
const int mod = 1e9 + 7;
int C[maxn][maxn];
int dp[maxn][27];
int add(int x, int y) { return (x + y >= mod) ? (x + y - mod) : (x + y); }
signed main() {
  string s;
  vector<int> a;
  ios ::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int len;
  cin >> len;
  cin >> s;
  a.clear();
  a.push_back(0);
  for (char x : s) {
    int c = x - 'a' + 1;
    if (c == a.back()) continue;
    a.push_back(c);
  }
  int n = len;
  C[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      C[i][j] = add(C[i - 1][j], C[i - 1][j - 1]);
    }
  }
  dp[0][0] = 1;
  for (int i = 1; i < a.size(); i++) {
    for (int j = i; j; j--) {
      int x = a[i], ans = 0;
      for (int c = 0; c <= 26; c++) {
        if (c ^ x) {
          ans = add(ans, dp[j - 1][c]);
        }
      }
      dp[j][x] = ans;
    }
  }
  int ans = 0;
  for (int i = 1; i < a.size(); i++) {
    int tmp = 0;
    for (int c = 1; c <= 26; c++) tmp = add(tmp, dp[i][c]);
    ans = add(ans, 1ll * C[n][i] * tmp % mod);
  }
  cout << ans << '\n';
  return 0;
}
