#include <bits/stdc++.h>
using namespace std;
struct subj {
  long long index, a, b, c;
  subj() { index = a = b = c = 0; }
};
bool operator<(subj d1, subj d2) {
  if (d1.c != d2.c) return d1.c < d2.c;
  return d1.index < d2.index;
}
const int MAXN = 50;
const int MAXM = 50;
const int MAXK = 100;
long long n, m, k;
subj s[MAXM + 10];
long long dp[MAXN + 10][MAXM + 10][MAXK + 10];
long long par[MAXN + 10][MAXM + 10][MAXK + 10];
long long paro[MAXN + 10][MAXM + 10][MAXK + 10];
void print(int i, int j, int o) {
  if (i == 0) {
    cout << s[j].index << ' ' << s[j].a + o << endl;
    return;
  }
  print(i - 1, par[i][j][o], paro[i][j][o]);
  cout << s[j].index << ' ' << s[j].a + o << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    cin >> s[i].a >> s[i].b >> s[i].c;
    s[i].index = i + 1;
  }
  sort(s, s + m);
  for (int j = 0; j < m; j++)
    for (int o = 0; o <= s[j].b - s[j].a; o++) dp[0][j][o] = o + s[j].a;
  for (int i = 1; i < n; i++)
    for (int j = 0; j < m; j++)
      for (int o = 1; o <= s[j].b - s[j].a; o++) {
        for (int p = j - 1; p >= 0; p--) {
          if (s[j].c == s[p].c) continue;
          if ((o + s[j].a) % k == 0 && ((o + s[j].a) / k) - s[p].a >= 0 &&
              ((o + s[j].a) / k) - s[p].a <= s[j].b - s[j].a &&
              dp[i - 1][p][((o + s[j].a) / k) - s[p].a] != 0) {
            if (dp[i - 1][p][((o + s[j].a) / k) - s[p].a] + o + s[j].a >
                dp[i][j][o]) {
              par[i][j][o] = p;
              paro[i][j][o] = ((o + s[j].a) / k) - s[p].a;
            }
            dp[i][j][o] =
                max(dp[i][j][o],
                    dp[i - 1][p][((o + s[j].a) / k) - s[p].a] + o + s[j].a);
          }
          if (o + s[j].a - k - s[p].a >= 0 &&
              o + s[j].a - k - s[p].a <= s[j].b - s[j].a &&
              dp[i - 1][p][o + s[j].a - k - s[p].a] != 0) {
            if (dp[i - 1][p][o + s[j].a - k - s[p].a] + o + s[j].a >
                dp[i][j][o]) {
              par[i][j][o] = p;
              paro[i][j][o] = o + s[j].a - k - s[p].a;
            }
            dp[i][j][o] =
                max(dp[i][j][o],
                    dp[i - 1][p][o + s[j].a - k - s[p].a] + o + s[j].a);
          }
        }
      }
  int maxm = 0, maxo = 0;
  for (int j = 0; j < m; j++)
    for (int o = 0; o <= s[j].b - s[j].a; o++) {
      if (dp[n - 1][j][o] > dp[n - 1][maxm][maxo]) {
        maxm = j;
        maxo = o;
      }
    }
  if (dp[n - 1][maxm][maxo] == 0) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  print(n - 1, maxm, maxo);
  return 0;
}
