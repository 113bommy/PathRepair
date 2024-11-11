#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-8;
struct Subject {
  long long a, b;
  int c, no;
};
bool operator<(const Subject& a, const Subject& b) { return a.c < b.c; }
int dp_prev[51][50][101];
long long dp[51][50][101];
int main() {
  int n, m, kk;
  Subject s[50];
  cin >> n >> m >> kk;
  for (int i = 0; i < m; ++i) {
    s[i].no = i + 1;
    cin >> s[i].a >> s[i].b >> s[i].c;
  }
  sort(s, s + m);
  for (int i = 0; i < m; ++i)
    for (int j = 0; j <= s[j].b - s[j].a; ++j) dp[1][i][j] = s[i].a + j;
  for (int i = 1; i < n; ++i)
    for (int j = 0; j < m; ++j)
      for (int k = 0; k <= s[j].b - s[j].a; ++k) {
        if (!dp[i][j][k]) continue;
        long long ex[2];
        ex[0] = s[j].a + k + kk;
        ex[1] = (s[j].a + k) * kk;
        for (int l = j + 1; l < m; ++l) {
          if (s[j].c < s[l].c) {
            for (int t = 0; t < 2; ++t) {
              if (s[l].a <= ex[t] && ex[t] <= s[l].b &&
                  dp[i][j][k] + ex[t] > dp[i + 1][l][ex[t] - s[l].a]) {
                dp[i + 1][l][ex[t] - s[l].a] = dp[i][j][k] + ex[t];
                dp_prev[i + 1][l][ex[t] - s[l].a] = j * 1000 + k;
              }
            }
          }
        }
      }
  long long maxi;
  int mi, mj;
  maxi = 0;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j <= s[i].b - s[i].a; ++j) {
      if (dp[n][i][j] > maxi) {
        maxi = dp[n][i][j];
        mi = i;
        mj = j;
      }
    }
  }
  if (maxi) {
    stack<string> line;
    for (int t = n, i = mi, j = mj; t; --t) {
      stringstream ss;
      int prev = dp_prev[t][i][j];
      int pi = prev / 1000;
      int pj = prev % 1000;
      ss << s[i].no << ' ' << dp[t][i][j] - dp[t - 1][pi][pj];
      line.push(ss.str());
      i = pi;
      j = pj;
    }
    puts("YES");
    while (!line.empty()) {
      cout << line.top() << endl;
      line.pop();
    }
  } else
    puts("NO");
  return 0;
}
