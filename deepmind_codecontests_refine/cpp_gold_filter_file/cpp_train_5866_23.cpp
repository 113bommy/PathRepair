#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3030;
const int MAXM = 310;
double posb[MAXN][MAXM];
double rec[MAXM][MAXN];
double buf[MAXN];
priority_queue<pair<double, int> > que;
int main() {
  int N, M;
  scanf("%d%d", &N, &M);
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++) {
      int a;
      scanf("%d", &a);
      posb[i][j] = (double)a / 1000.0;
    }
  for (int i = 1; i <= M; i++) {
    for (int j = 1; j <= N; j++)
      rec[i][j] = rec[i][j - 1] * (1.0 - posb[j][i]) + posb[j][i];
    que.push(pair<double, int>(rec[i][N], i));
  }
  double ans = 0;
  for (int p = 1; p <= N; p++) {
    pair<double, int> pr = que.top();
    que.pop();
    int i = pr.second;
    memcpy(buf, rec[i], sizeof buf);
    for (int j = 1; j <= N; j++)
      rec[i][j] =
          rec[i][j - 1] * (1.0 - posb[j][i]) + (buf[j - 1] + 1) * posb[j][i];
    que.push(pair<double, int>(rec[i][N] - buf[N], i));
    ans += pr.first;
  }
  printf("%.9lf\n", ans);
}
