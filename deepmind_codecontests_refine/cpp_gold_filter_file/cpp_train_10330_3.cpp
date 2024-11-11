#include <bits/stdc++.h>
using namespace std;
const long double pai = 3.1415926536;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const unsigned long long bas = 2333;
const int MAXN = 1e5 + 10;
const int N = 1010;
const long long mod = 1e9 + 7;
template <typename T>
void read(T &x) {
  char ch = getchar();
  x = 0;
  int f = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  x *= f;
}
struct edge {
  int to;
  long long dis;
  edge() = default;
  edge(int a, long long b) : to(a), dis(b) {}
};
char s[410], t[410];
int nxt[410][30], dp[410][410];
int main() {
  ios::sync_with_stdio(false);
  int T = 1;
  cin >> T;
  while (T--) {
    int n, m, f = 0;
    cin >> s + 1 >> t + 1;
    n = strlen(s + 1);
    m = strlen(t + 1);
    for (int i = 0; i < 26; ++i) nxt[n][i] = nxt[n + 2][i] = n + 2;
    for (int i = n - 1; i >= 0; --i) {
      memcpy(nxt[i], nxt[i + 1], sizeof(nxt[i]));
      nxt[i][s[i + 1] - 'a'] = i + 1;
    }
    dp[0][0] = 0;
    for (int i = 1; i <= m; ++i) dp[i][0] = nxt[dp[i - 1][0]][t[i] - 'a'];
    for (int k = 1; k <= m; ++k) {
      for (int i = 1; i <= m - k; ++i)
        dp[0][i] = nxt[dp[0][i - 1]][t[k + i] - 'a'];
      for (int i = 1; i <= k; ++i) {
        for (int j = 1; j <= m - k; ++j)
          dp[i][j] = min(nxt[dp[i - 1][j]][t[i] - 'a'],
                         nxt[dp[i][j - 1]][t[k + j] - 'a']);
      }
      if (dp[k][m - k] <= n) {
        f = 1;
        break;
      }
    }
    if (f)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
