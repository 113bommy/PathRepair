#include <bits/stdc++.h>
using namespace std;
const int MAX = 2505;
double dist[MAX][MAX];
double dp[MAX][MAX][2];
pair<double, double> p[MAX];
int n;
double sq(double x) { return x * x; }
double distance(pair<double, double> a, pair<double, double> b) {
  return sqrt(sq(a.first - b.first) + sq(a.second - b.second));
}
int nxt(int a) {
  if (a == n - 1) return 0;
  return a + 1;
}
int prv(int a) {
  if (!a) return n - 1;
  return a - 1;
}
double rek(int a, int b, int st) {
  if (nxt(a) == b) return 0;
  if (dp[a][b][st] >= 0) return dp[a][b][st];
  double ret = 0;
  int ja = st ? b : a;
  ret = max(rek(nxt(a), b, 0) + dist[ja][nxt(a)],
            rek(a, prv(b), 1) + dist[ja][prv(b)]);
  return dp[a][b][st] = ret;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%lf%lf", &p[i].first, &p[i].second);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) dist[i][j] = distance(p[i], p[j]);
  for (int i = 0; i < MAX; i++)
    for (int j = 0; j < MAX; j++) dp[i][j][0] = dp[i][j][1] = -1;
  double rje = 0;
  for (int i = 0; i < n; i++) rje = max(rje, rek(i, i, 0));
  printf("%lf\n", rje);
  return 0;
}
