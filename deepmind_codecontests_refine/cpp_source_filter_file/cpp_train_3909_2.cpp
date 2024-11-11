#include <bits/stdc++.h>
using namespace std;
const int nax = 1005;
int dist[nax][nax];
vector<int> w[nax];
double p_later[nax];
double p_dist_max[nax];
bool vis[nax];
void max_self(double& a, double b) { a = max(a, b); }
double consider_tomorrow(int n, int g1, int dist1) {
  double best_tomorrow = 0;
  for (int i = 1; i <= n; ++i) {
    p_later[i] = 0;
    vis[i] = false;
  }
  vector<int> interesting;
  for (int v = 1; v <= n; ++v)
    if (dist[g1][v] == dist1)
      for (int b : w[v]) {
        p_later[b] += (double)1 / n / w[v].size();
        if (!vis[b]) {
          vis[b] = true;
          interesting.push_back(b);
        }
      }
  for (int g2 = 1; g2 <= n; ++g2) {
    double local_sum = 0;
    for (int b : interesting) max_self(p_dist_max[dist[g2][b]], p_later[b]);
    for (int b : interesting) {
      local_sum += p_dist_max[dist[g2][b]];
      p_dist_max[dist[g2][b]] = 0;
    }
    max_self(best_tomorrow, local_sum);
  }
  return best_tomorrow;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = (1); i <= (n); ++i)
    for (int j = (1); j <= (n); ++j)
      if (i != j) dist[i][j] = n + 1;
  for (int i = (1); i <= (m); ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    w[a].push_back(b);
    w[b].push_back(a);
    dist[a][b] = dist[b][a] = 1;
  }
  for (int b = (1); b <= (n); ++b)
    for (int a = (1); a <= (n); ++a)
      for (int c = (1); c <= (n); ++c)
        dist[a][c] = min(dist[a][c], dist[a][b] + dist[b][c]);
  double answer = 0;
  for (int g1 = (1); g1 <= (n); ++g1) {
    double sum_over_dist1 = 0;
    for (int dist1 = (0); dist1 <= (n); ++dist1) {
      int cnt_cities = 0;
      for (int i = (1); i <= (n); ++i)
        if (dist[g1][i] == dist1) ++cnt_cities;
      if (cnt_cities == 0) continue;
      double immediately = (double)1 / n;
      double second_day = consider_tomorrow(n, g1, dist1);
      sum_over_dist1 += max(immediately, second_day);
    }
    max_self(answer, sum_over_dist1);
  }
  printf("%.12lfn", (double)answer);
  return 0;
}
