#include <bits/stdc++.h>
using namespace std;
long double dp[301][3001];
long double vas[301][3001];
int a[301][3001];
int n, m;
long double tmp[3001];
inline void cal(int x, int now) {
  for (int i = 1; i <= n; ++i) tmp[i] = 0;
  for (int i = now; i <= n; ++i) {
    tmp[i] = (tmp[i - 1] * (1000 - a[x][i]) / 1000) +
             (dp[x][i - 1] * a[x][i] / 1000);
  }
  for (int i = 1; i <= n; ++i) dp[x][i] = tmp[i];
  vas[x][now + 1] = vas[x][now] - dp[x][n];
}
struct dat {
  long double va;
  int x, pos;
  bool operator<(const dat& a) const { return va < a.va; }
};
priority_queue<dat> q;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      scanf("%d", &a[j][i]);
    }
  }
  for (int i = 1; i <= m; ++i) {
    dp[i][0] = 1;
    for (int j = 1; j <= n; ++j) {
      dp[i][j] = dp[i][j - 1] * (1000 - a[i][j]) / 1000;
    }
  }
  for (int i = 1; i <= m; ++i) {
    vas[i][0] = 1;
    vas[i][1] = 1 - dp[i][n];
    q.push((dat){vas[i][1], i, 1});
  }
  long double as = 0;
  for (int i = 1; i <= n; ++i) {
    dat x = q.top();
    q.pop();
    as += x.va;
    cal(x.x, x.pos);
    q.push((dat){vas[x.x][x.pos + 1], x.x, x.pos + 1});
  }
  printf("%.10lf\n", (double)as);
  return 0;
}
