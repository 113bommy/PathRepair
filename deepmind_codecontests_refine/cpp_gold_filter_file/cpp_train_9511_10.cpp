#include <bits/stdc++.h>
using namespace std;
int a, b, c, d, e, f, g, h, i, j, k;
double F[1005][1005];
double C[1005][1005];
vector<int> G[1005], GG;
bool v[1005];
int cnt, H;
int must[1005];
double u, w;
double t;
bool cmp(int x, int y) { return x > y; }
int main() {
  scanf("%d%d", &a, &b);
  for (i = 1; i <= b; i++) {
    scanf("%d", &c);
    for (j = 1; j <= c; j++) {
      scanf("%d", &d);
      GG.push_back(d);
      G[i].push_back(d);
    }
  }
  sort(GG.begin(), GG.end(), cmp);
  d = GG[a - 1];
  e = 0;
  for (i = 1; i <= b; i++) {
    v[i] = false;
    for (j = 0; j < G[i].size(); j++) {
      if (G[i][j] > d) {
        must[i]++;
        e++;
      }
      if (G[i][j] == d) {
        v[i] = true;
        cnt++;
      }
    }
  }
  C[0][0] = 1;
  C[1][0] = 1;
  C[1][1] = 1;
  for (i = 2; i <= 1000; i++) {
    C[i][0] = 1;
    for (j = 1; j <= i; j++) C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
  }
  F[0][0] = 1;
  for (i = 1; i <= b; i++) {
    for (j = 0; j <= a - e; j++) {
      if (v[i] == false) {
        F[i][j] = F[i - 1][j] / C[G[i].size()][must[i]];
        continue;
      }
      if (cnt != 0)
        t = (double)(a - e - j) / (double)(cnt);
      else
        t = 0;
      F[i][j] += F[i - 1][j] / C[G[i].size()][must[i]] * (1 - t);
      F[i][j + 1] += F[i - 1][j] / C[G[i].size()][must[i] + 1] * t;
    }
    cnt -= v[i];
  }
  printf("%.10lf\n", F[b][a - e]);
  return 0;
}
