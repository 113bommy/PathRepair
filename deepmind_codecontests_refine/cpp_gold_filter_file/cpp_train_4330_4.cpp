#include <bits/stdc++.h>
using namespace std;
const int N = 1007;
const int G = 19491001;
const int mod = 1019260817;
const int mxlen = 1001;
void Min(int &x, int y) {
  if (x > y) x = y;
}
void Max(int &x, int y) {
  if (x < y) x = y;
}
string s[N], now;
int n, len[N], Len, w[N], has[N][N], dp[N][N], p[N], Pow[N], hz[N], hv[N];
int get(int x, int l, int r) {
  return (has[x][r] - (l == 0 ? 0 : has[x][l - 1]) + mod) % mod;
}
int D[N], arr[N], tot;
bool cmp(int x, int y) { return D[x] > D[y]; }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> now >> n, Len = now.size(), reverse(now.begin(), now.end());
  Pow[0] = 1;
  for (int i = 1, iE = 1001; i <= iE; i++)
    Pow[i] = (long long)Pow[i - 1] * G % mod;
  for (int i = 1, iE = n; i <= iE; i++)
    cin >> s[i], len[i] = (int)s[i].size(), reverse(s[i].begin(), s[i].end()),
                 p[i] = i;
  for (int i = 0, iE = 9; i <= iE; i++) cin >> w[i];
  for (int i = 1, iE = n; i <= iE; i++) {
    for (int j = 0, jE = len[i] - 1; j <= jE; j++) {
      has[i][j] = (long long)s[i][j] * Pow[j] % mod;
      if (j) (has[i][j] += has[i][j - 1]) %= mod;
    }
  }
  for (int i = 1, iE = n; i <= iE; i++) D[i] = 1;
  memset(dp, -0x3f, sizeof(dp));
  dp[0][0] = 0;
  for (int i = 0, iE = mxlen; i <= iE; i++) {
    if (i) {
      tot = 0;
      for (int j = 1, jE = n; j <= jE; j++)
        if (i <= len[j]) D[j] += (s[j][i - 1] - '0') * (n + 1);
      for (int j = 1, jE = n; j <= jE; j++) arr[++tot] = D[j];
      sort(arr + 1, arr + tot + 1),
          tot = unique(arr + 1, arr + tot + 1) - arr - 1;
      for (int j = 1, jE = n; j <= jE; j++)
        D[j] = lower_bound(arr + 1, arr + tot + 1, D[j]) - arr;
      sort(p + 1, p + n + 1, cmp);
    }
    int l = (i == Len - 1), r = 9;
    if ((int)Len <= i)
      l = r = 0;
    else if (now[i] != '?')
      l = r = now[i] - '0';
    for (int d = l, dE = r; d <= dE; d++) {
      int now = 0, all = 0;
      for (int j = n, jE = 1; j >= jE; j--) {
        int v = (i > len[p[j]] - 1 ? 0 : s[p[j]][i] - '0');
        hv[j] = hv[j + 1], hz[j] = hz[j + 1];
        if (v + d || i < max(len[p[j]], Len))
          hv[j] += w[(v + d) % 10], hz[j] += (v + d) / 10;
      }
      for (int j = 0, jE = n; j <= jE; j++) {
        if (j) {
          int v = (i > len[p[j]] - 1 ? 0 : s[p[j]][i] - '0');
          all += w[(v + d + 1) % 10];
          now += (v + d + 1) / 10;
        }
        Max(dp[i + 1][now + hz[j + 1]], dp[i][j] + all + hv[j + 1]);
      }
    }
  }
  cout << dp[mxlen + 1][0] << endl;
  return 0;
}
