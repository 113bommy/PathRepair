#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};
int vis[1001][1001][2];
double dp[1001][1001][2];
double calc(int b, int w, int f) {
  if (!f && !b && w) return 1;
  if (!w || !b) return 0;
  if (vis[b][w][f] != -1) return dp[b][w][f];
  double res = 0;
  if (!f && b)
    res += (double(w) / double(w + b)) +
           (calc(b - 1, w, !f) * (double)(b) / (double)(w + b));
  if (b >= 2 && f)
    res += calc(b - 2, w, !f) * double(b) / double(w + b) * double(b - 1) /
           double(w + b - 1);
  if (b && w && f)
    res += calc(b - 1, w - 1, !f) * (double(b) / double(w + b)) *
           (double(w) / double(w + b - 1));
  vis[b][w][f] = 1;
  return dp[b][w][f] = res;
}
int main() {
  memset(vis, -1, sizeof(vis));
  int b, w;
  cin >> w >> b;
  printf("%.9lf\n", calc(b, w, 0));
  return 0;
}
