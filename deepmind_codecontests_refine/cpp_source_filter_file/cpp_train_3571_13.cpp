#include <bits/stdc++.h>
using namespace std;
const unsigned long long hash1 = 201326611;
const double eps = 1e-6;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const long long mod = 1e9 + 7;
const long long MMD = mod * mod;
const int N = 1e3 + 10;
const int M = 2e2 + 10;
const int dif = 26;
const double PI = acos(-1.0);
inline void Mod(long long& x) {
  if (x >= mod) x -= mod;
}
int w, b;
set<pair<int, int> > s[2];
double dp[2][N][N];
set<pair<int, int> >::iterator ite;
int main() {
  scanf("%d%d", &w, &b);
  double ans = 0;
  if (w == 0) {
    printf("%.9lf\n", 0);
    return 0;
  } else if (b == 0) {
    printf("%.9lf\n", 1);
    return 0;
  }
  dp[0][0][0] = 1;
  s[0].insert(make_pair(0, 0));
  bool tag = 0, flag;
  for (int i = 1;; i ^= 1) {
    if (s[i ^ 1].size() == 0) break;
    for (int j = 0; j <= w; j++)
      for (int k = 0; k <= b; k++) dp[i][j][k] = 0;
    ite = s[i ^ 1].begin();
    while (ite != s[i ^ 1].end()) {
      int j = (*ite).first, k = (*ite).second;
      ite++;
      if (!tag) {
        if (j + 1 <= w) {
          ans += dp[i ^ 1][j][k] * (w - j) / (w - j + b - k);
        }
        if (k + 1 <= b) {
          dp[i][j][k + 1] += dp[i ^ 1][j][k] * (b - k) / (w - j + b - k);
          s[i].insert(make_pair(j, k + 1));
        }
      } else {
        if (k + 2 <= b) {
          dp[i][j][k + 2] += dp[i ^ 1][j][k] *
                             ((b - k + 0.0) / (w - j + b - k)) *
                             ((b - k - 1 + 0.0) / (w - j + b - k - 1));
          s[i].insert(make_pair(j, k + 2));
        }
        if (k + 1 <= b && j + 1 < w) {
          dp[i][j + 1][k + 1] += dp[i ^ 1][j][k] *
                                 ((b - k + 0.0) / (w - j + b - k)) *
                                 ((w - j + 0.0) / (w - j + b - k - 1));
          s[i].insert(make_pair(j + 1, k + 1));
        }
      }
    }
    for (ite = s[i ^ 1].begin(); ite != s[i ^ 1].end(); ite++) {
      int j = (*ite).first, k = (*ite).second;
      dp[i ^ 1][j][k] = 0;
    }
    s[i ^ 1].clear();
    tag ^= 1;
  }
  printf("%.9lf\n", ans);
}
