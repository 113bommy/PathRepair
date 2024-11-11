#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
const double eps = 1e-7;
const int inf = 0x3f3f3f3f;
int n, l, N[MAXN];
double dp[MAXN];
struct Node {
  int W, C;
} arr[MAXN];
bool Check(double x) {
  for (int i = 1; i <= n; i++) dp[i] = inf;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < i; j++) {
      double v = dp[j] + sqrt(fabs(arr[i].W - arr[j].W - l)) - arr[i].C * x;
      if (dp[i] > v) {
        dp[i] = v;
        N[i] = j;
      }
    }
  }
  return dp[n] > 0;
}
void Search(int x) {
  if (N[x] == 0) return;
  Search(N[x]);
  printf("%d ", N[x]);
}
int main() {
  scanf("%d%d", &n, &l);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &arr[i].W, &arr[i].C);
  }
  double l = 0, r = 1e9, mid;
  while (l < (r - eps)) {
    mid = (l + r) / 2;
    if (Check(mid))
      l = mid;
    else {
      r = mid;
    }
  }
  Search(n);
  printf("%d", n);
  return 0;
}
