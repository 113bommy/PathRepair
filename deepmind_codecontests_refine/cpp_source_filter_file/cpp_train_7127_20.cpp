#include <bits/stdc++.h>
using namespace std;
int n, k;
char A[2000200], B[2000200];
int E[55][55];
vector<vector<double> > e;
vector<double> e2;
vector<int> a, b;
double MinCostMatching(const vector<vector<double> > &cost, vector<int> &Lmate,
                       vector<int> &Rmate) {
  int n = int(cost.size());
  vector<double> u(n);
  vector<double> v(n);
  for (int i = 0; i < n; i++) {
    u[i] = cost[i][0];
    for (int j = 1; j < n; j++) u[i] = min(u[i], cost[i][j]);
  }
  for (int j = 0; j < n; j++) {
    v[j] = cost[0][j] - u[0];
    for (int i = 1; i < n; i++) v[j] = min(v[j], cost[i][j] - u[i]);
  }
  Lmate = vector<int>(n, -1);
  Rmate = vector<int>(n, -1);
  int mated = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (Rmate[j] != -1) continue;
      if (fabs(cost[i][j] - u[i] - v[j]) < 1e-10) {
        Lmate[i] = j;
        Rmate[j] = i;
        mated++;
        break;
      }
    }
  }
  vector<double> dist(n);
  vector<int> dad(n);
  vector<int> seen(n);
  while (mated < n) {
    int s = 0;
    while (Lmate[s] != -1) s++;
    fill(dad.begin(), dad.end(), -1);
    fill(seen.begin(), seen.end(), 0);
    for (int k = 0; k < n; k++) dist[k] = cost[s][k] - u[s] - v[k];
    int j = 0;
    while (true) {
      j = -1;
      for (int k = 0; k < n; k++) {
        if (seen[k]) continue;
        if (j == -1 || dist[k] < dist[j]) j = k;
      }
      seen[j] = 1;
      if (Rmate[j] == -1) break;
      const int i = Rmate[j];
      for (int k = 0; k < n; k++) {
        if (seen[k]) continue;
        const double new_dist = dist[j] + cost[i][k] - u[i] - v[k];
        if (dist[k] > new_dist) {
          dist[k] = new_dist;
          dad[k] = j;
        }
      }
    }
    for (int k = 0; k < n; k++) {
      if (k == j || !seen[k]) continue;
      const int i = Rmate[k];
      v[k] += dist[k] - dist[j];
      u[i] -= dist[k] - dist[j];
    }
    u[s] += dist[j];
    while (dad[j] >= 0) {
      const int d = dad[j];
      Rmate[j] = Rmate[d];
      Lmate[Rmate[j]] = j;
      j = d;
    }
    Rmate[j] = s;
    Lmate[s] = j;
    mated++;
  }
  double value = 0;
  for (int i = 0; i < n; i++) value += cost[i][Lmate[i]];
  return value;
}
int main() {
  scanf("%d%d", &n, &k);
  scanf("%s", A);
  scanf("%s", B);
  memset(E, 0, sizeof(E));
  for (int i = 0; i < n; i++) {
    int x, y;
    x = (A[i] >= 'a') ? A[i] - 'a' : A[i] - 'A' + 26;
    y = (B[i] >= 'a') ? B[i] - 'a' : B[i] - 'A' + 26;
    E[x][y]++;
  }
  e.clear();
  for (int i = 0; i < k; i++) {
    e2.clear();
    for (int j = 0; j < k; j++) e2.push_back(n + 1 - E[i][j]);
    e.push_back(e2);
  }
  double ans = MinCostMatching(e, a, b);
  ans = (n + 1) * k - ans;
  printf("%.0lf\n", ans);
  for (int i = 0; i < a.size(); i++) {
    char c;
    if (a[i] < 26)
      c = a[i] + 'a';
    else
      c = a[i] + 'A';
    printf("%c", c);
  }
  printf("\n");
  return 0;
}
