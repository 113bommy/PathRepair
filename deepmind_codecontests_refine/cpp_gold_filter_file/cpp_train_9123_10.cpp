#include <bits/stdc++.h>
using namespace std;
vector<double> pile[55 * 55];
vector<int> vis[55 * 55];
int p[55];
int ans[55 * 55];
int main() {
  double n, w, m, x, y, tot;
  scanf("%lf %lf %lf", &n, &w, &m);
  x = w / m;
  y = (n * w) / m;
  int all = 1, pos;
  for (int i = 1; i <= (int)n * m; i++) {
    if (i % (int)m != 0)
      ans[i] = all;
    else {
      ans[i] = all;
      all++;
    }
  }
  all = 0;
  pos = 0;
  ans[0] = 1;
  for (int i = 1; i <= (int)m; i++) {
    tot = y / x;
    for (int j = 1; j <= n; j++) {
      all++;
      if (ans[all] != ans[all - 1]) {
        double sum = double(all - pos - 1) * x;
        if (sum != 0) {
          pile[i].push_back(sum);
          vis[i].push_back(ans[all - 1]);
          pos = all - 1;
        }
      }
    }
    double sum = double(all - pos) * x;
    if (sum != 0) {
      pos = all;
      pile[i].push_back(sum);
      vis[i].push_back(ans[all]);
    }
  }
  for (int i = 1; i <= (int)m; i++) {
    for (int j = 0; j < vis[i].size(); j++) {
      int l = vis[i][j];
      p[l]++;
      if (p[l] > 2) {
        printf("NO");
        return 0;
      }
    }
  }
  printf("YES\n");
  for (int i = 1; i <= (int)m; i++) {
    for (int j = 0; j < pile[i].size(); j++) {
      printf("%d %lf ", vis[i][j], pile[i][j]);
    }
    printf("\n");
  }
}
