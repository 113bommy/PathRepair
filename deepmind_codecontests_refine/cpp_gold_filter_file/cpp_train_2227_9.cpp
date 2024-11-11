#include <bits/stdc++.h>
using namespace std;
const long long INF = 100000000005;
int n, m, k;
struct Node {
  long long x;
  long long y;
} node[1000005];
long long mi_x_up[1000005];
long long mx_x_up[1000005];
long long mi_x_down[1000005];
long long mx_x_down[1000005];
bool cmp(const Node &a, const Node &b) {
  if (a.y != b.y)
    return a.y < b.y;
  else
    return a.x < b.x;
}
bool judge(long long tmp) {
  long long x_mi;
  long long x_mx;
  for (int i = 1, j = 1; i < n; i++) {
    long long up = node[i].y + tmp;
    while (node[j + 1].y <= up && j + 1 <= n) j++;
    x_mi = min(mi_x_up[i - 1], mi_x_down[j + 1]);
    x_mx = max(mx_x_up[i - 1], mx_x_down[j + 1]);
    if (x_mx - x_mi <= tmp) return true;
  }
  return false;
}
int main() {
  while (scanf("%d", &n) == 1) {
    for (int i = 1; i <= n; i++) {
      long long u, v;
      scanf("%I64d%I64d", &u, &v);
      node[i].x = u - v;
      node[i].y = u + v;
    }
    sort(node + 1, node + 1 + n, cmp);
    mi_x_up[0] = INF;
    mx_x_up[0] = -INF;
    mi_x_up[n + 1] = INF;
    mx_x_up[n + 1] = -INF;
    for (int i = 1; i <= n; i++) {
      mi_x_up[i] = min(mi_x_up[i - 1], node[i].x);
      mx_x_up[i] = max(mx_x_up[i - 1], node[i].x);
    }
    mi_x_down[0] = INF;
    mx_x_down[0] = -INF;
    mi_x_down[n + 1] = INF;
    mx_x_down[n + 1] = -INF;
    for (int i = n; i >= 1; i--) {
      mi_x_down[i] = min(mi_x_down[i + 1], node[i].x);
      mx_x_down[i] = max(mx_x_down[i + 1], node[i].x);
    }
    long long L = 0;
    long long R = 100000000005;
    while (R - L > 0) {
      long long mid = (L + R) / 2;
      if (judge(mid))
        R = mid;
      else
        L = mid + 1;
    }
    double ans = L * 0.5;
    printf("%.15f\n", ans);
  }
  return 0;
}
