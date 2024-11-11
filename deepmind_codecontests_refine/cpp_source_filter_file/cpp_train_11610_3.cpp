#include <bits/stdc++.h>
using namespace std;
int n, temp;
double p[1000][1000];
double dis[1000], q[1000];
bool vis[1000];
int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      scanf("%d", &temp);
      p[i][j] = temp / 100.0;
    }
  for (int i = 0; i < n; i++) {
    q[i] = p[i][n - 1];
    if (p[i][n - 1] > 0.003)
      dis[i] = 1 / p[i][n - 1];
    else
      dis[i] = 1e12;
  }
  dis[n - 1] = 0;
  vis[n - 1] = 1;
  for (int i = 0; i < n; i++) {
    temp = -1;
    for (int j = 0; j < n; j++)
      if (!vis[j] && (temp == -1 || dis[j] < dis[temp])) temp = j;
    if (temp == -1) break;
    vis[temp] = 1;
    for (int j = 0; j < n; j++)
      if (!vis[j]) {
        if (q[j] > 0) {
          dis[j] = dis[j] * q[j] + q[j] * p[j][temp] * dis[temp];
          q[j] = q[j] + (1 - q[j]) * p[j][temp];
          dis[j] /= q[j];
        } else {
          q[j] = p[j][temp];
          if (q[j] > 0.003) dis[j] = dis[temp] + 1 / q[j];
        }
      }
  }
  printf("%.12lf\n", dis[0]);
  return 0;
}
