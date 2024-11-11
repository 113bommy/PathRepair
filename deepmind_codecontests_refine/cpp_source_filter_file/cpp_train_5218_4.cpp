#include <bits/stdc++.h>
using namespace std;
inline bool isvowel(char c) {
  c = tolower(c);
  if (c == 'a' || c == 'e' || c == 'i' || c == 'y' || c == 'o' || c == 'u')
    return 1;
  return 0;
}
const double eps = 0.000001;
const long double pi = acos(-1);
const int maxn = 1e7 + 9;
const int mod = 1e9 + 7;
const long long MOD = 1e18 + 9;
const long long INF = 1e18 + 123;
const int inf = 2e9 + 11;
const int mxn = 1e6 + 9;
const int N = 1123;
const int M = 22;
const int pri = 997;
const int Magic = 2101;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
int n, m;
string s[N];
int dp[N][N];
int res = -1;
int u[N], can[N];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    s[i] = 'z' + s[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int cur = 0;
      if (s[i][j] == 'a') cur++;
      dp[i][j] = cur;
      dp[i][j] = max(dp[i][j], cur + max(dp[i - 1][j], dp[i][j - 1]));
      if (i + j - 2 < dp[i][j] + m) res = max(res, i + j);
    }
  }
  if (res == -1) {
    res = 1;
    u[2] = 1;
  } else {
    for (int i = 1; i <= n; i++) {
      int j = res - i;
      if (j > n || j < 0) continue;
      if (i + j - 2 < dp[i][j] + m) {
        if (i < n) u[i + 1] = 1;
        if (j < n) u[i] = 1;
      }
    }
    for (int i = 2; i <= res; i++) {
      cout << 'a';
    }
    res++;
  }
  while (res <= n * 2) {
    char mn = 'z';
    for (int i = 1; i <= n; i++) {
      if (u[i]) {
        mn = min(mn, s[i][res - i]);
      }
    }
    cout << mn;
    for (int i = 1; i <= n; i++) {
      if (u[i] && s[i][res - i] == mn) {
        if (i < n) can[i + 1] = 1;
        if (res - i < n) can[i] = 1;
      }
    }
    res++;
    for (int i = 1; i <= n; i++) {
      u[i] = can[i];
      can[i] = 0;
    }
  }
  return 0;
}
