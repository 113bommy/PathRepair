#include <bits/stdc++.h>
using namespace std;
void task();
int main() {
  task();
  return 0;
}
const int N = (int)1e5 + 10;
const int MODULO = (int)1e9 + 3;
const long long int INF = (long long int)1e18;
const int BUF_SIZE = (int)1e5 + 10;
struct St {
  long long int a, b;
  int c;
  int num;
  friend bool operator<(St const& a, St const& b) { return a.c < b.c; }
};
int n, m, koef;
St a[60];
long long int dp[60][60][110];
pair<int, int> from[60][60][110];
void task() {
  scanf("%d %d %d", &n, &m, &koef);
  for (int i = 0; i < m; ++i) {
    scanf("%I64d %I64d %d", &a[i].a, &a[i].b, &a[i].c);
    a[i].num = i + 1;
  }
  sort(a, a + m);
  for (int i = 0; i < m; ++i)
    for (int j = 0; j <= (int)(a[i].b - a[i].a); ++j) {
      dp[1][i][j] = a[i].a + j;
      from[1][i][j] = {-1, -1};
    }
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      for (int k = 0; k <= (int)(a[j].b - a[j].a + 1); ++k) {
        if (dp[i][j][k] == 0) continue;
        long long int nval[2] = {a[j].a + k + koef, (a[j].a + k) * koef};
        for (int next = j + 1; next < m; ++next) {
          if (a[next].c <= a[j].c) continue;
          for (int vind = 0; vind < 2; ++vind)
            if (a[next].a <= nval[vind] && nval[vind] <= a[next].b) {
              if (dp[i + 1][next][nval[vind] - a[next].a] <
                  dp[i][j][k] + nval[vind]) {
                dp[i + 1][next][nval[vind] - a[next].a] =
                    dp[i][j][k] + nval[vind];
                from[i + 1][next][nval[vind] - a[next].a] = {j, k};
              }
            }
        }
      }
    }
  }
  int maxi = -1, maxj = -1;
  long long int tans = 0;
  for (int i = 0; i < m; ++i)
    for (int j = 0; j <= (int)(a[i].b - a[i].a + 1); ++j) {
      if (dp[n][i][j] > tans) {
        tans = dp[n][i][j];
        maxi = i, maxj = j;
      }
    }
  vector<pair<int, int> > ans;
  int i = n;
  while (maxi != -1 && maxj != -1) {
    ans.push_back({maxi, maxj});
    int t = maxi;
    maxi = from[i][t][maxj].first;
    maxj = from[i][t][maxj].second;
    --i;
  }
  if (ans.size() == 0) {
    printf("NO");
  } else {
    printf("YES\n");
    for (int i = ans.size() - 1; i >= 0; --i) {
      printf("%d %I64d\n", a[ans[i].first].num,
             a[ans[i].first].a + ans[i].second);
    }
  }
}
