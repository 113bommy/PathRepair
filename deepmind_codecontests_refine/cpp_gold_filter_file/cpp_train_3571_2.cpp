#include <bits/stdc++.h>
using namespace std;
double DP[1001][1001][2], vis[1001][1001][2] = {0};
double dp(int w, int b, int in) {
  if (b < 0) return 0;
  if (vis[w][b][in]) return DP[w][b][in];
  if (in == 0) {
    if (w == 0)
      return 0;
    else if (b == 0)
      return 1;
    DP[w][b][in] = w + b * dp(w, b - 1, 1);
    DP[w][b][in] /= (w + b);
  } else {
    if (b == 0)
      return 0;
    else if (w == 0)
      return 0;
    DP[w][b][in] = b * (b - 1) * dp(w, b - 2, 0) + b * w * dp(w - 1, b - 1, 0);
    DP[w][b][in] /= (w + b) * (w + b - 1);
  }
  vis[w][b][in] = 1;
  return DP[w][b][in];
}
int main() {
  int n, i, temp, temp2;
  scanf("%d%d", &temp, &temp2);
  memset(vis, 0, sizeof(vis));
  printf("%.10lf\n", dp(temp, temp2, 0));
  return 0;
}
