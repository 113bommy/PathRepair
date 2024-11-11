#include <bits/stdc++.h>
using namespace std;
inline int in() {
  int32_t x;
  scanf("%d", &x);
  return x;
}
inline long long lin() {
  long long x;
  scanf("%lld", &x);
  return x;
}
inline string get() {
  char ch[2000010];
  scanf("%s", ch);
  return ch;
}
const int MAX_LG = 21;
const long long maxn = 105;
const long long maxm = 1e4;
const long long base = 29;
const long long mod = 1e9 + 7;
const long long INF = 1e18 + 100;
long long dp[maxn][26][700];
long long mp[30][30];
inline void gchar(char &ch) {
  do {
    ch = getchar();
  } while (!(ch >= 'a' && ch <= 'z'));
}
long long res;
int32_t main() {
  string s = get();
  long long k = in();
  long long q = in();
  long long n = s.size();
  for (long long i = 0; i < 26; i++) {
    if (s[0] - 'a' != i) dp[0][i][0] = -INF;
  }
  for (long long i = 1; i <= n; i++)
    for (long long j = 0; j < 26; j++)
      for (long long change = 0; change <= k; change++) dp[i][j][change] = -INF;
  while (q--) {
    char a, b;
    long long score;
    gchar(a), gchar(b);
    score = in();
    mp[a - 'a'][b - 'a'] = score;
  }
  for (long long i = 1; i < n; i++) {
    for (long long prechange = 0; prechange <= k; prechange++) {
      for (long long prechar = 0; prechar < 26; prechar++) {
        for (long long now = 0; now < 26; now++) {
          dp[i][now][prechange + bool(now != s[i] - 'a')] =
              max(dp[i][now][prechange + bool(now != s[i] - 'a')],
                  dp[i - 1][prechar][prechange] + mp[prechar][now]);
        }
      }
    }
  }
  for (long long i = 0; i < 26; i++) {
    res = max(res, dp[n - 1][i][k]);
  }
  cout << res << "\n";
}
