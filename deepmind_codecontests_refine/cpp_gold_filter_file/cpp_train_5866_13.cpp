#include <bits/stdc++.h>
using namespace std;
int n, m;
double f[305][3005][2], prob[3005][305];
struct box {
  int size;
};
struct compare {
  bool operator()(const box& p, const box& q) {
    return f[p.size][n][1] < f[q.size][n][1];
  }
};
priority_queue<box, vector<box>, compare> pq;
void func(int sz) {
  for (int i = 0; i <= n; i++) {
    f[sz][i][0] = f[sz][i][1];
    f[sz][i][1] = 0;
  }
  for (int i = 1; i <= n; i++)
    f[sz][i][1] =
        f[sz][i - 1][0] * prob[i][sz] + f[sz][i - 1][1] * (1 - prob[i][sz]);
  struct box pr;
  pr.size = sz;
  pq.push(pr);
}
int main() {
  int i, j, sz;
  double ans = 0;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) {
      scanf("%lf", &prob[i][j]);
      prob[i][j] /= 1000;
    }
  for (sz = 1; sz <= m; sz++) {
    for (j = 0; j <= n; j++) f[sz][j][1] = 1;
    func(sz);
  }
  for (i = 1; i <= n; i++) {
    struct box pr = pq.top();
    ans = ans + f[pr.size][n][1];
    pq.pop();
    func(pr.size);
  }
  printf("%.10lf\n", ans);
}
