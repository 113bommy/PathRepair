#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int n;
int y[maxn];
bool solve(double k) {
  int flag = 0;
  int point = -1;
  for (int i = 2; i <= n; i++) {
    if (y[i] - y[1] == k * (i - 1)) continue;
    flag = 1;
    if (point < 0)
      point = i;
    else if (y[i] - y[point] != k * (i - point)) {
      flag = 0;
      break;
    }
  }
  if (flag) return true;
  return false;
}
int main() {
  while (~scanf("%d", &n)) {
    for (int i = 1; i <= n; i++) {
      scanf("%d", &y[i]);
    }
    double k1 = 1.0 * (y[2] - y[1]);
    double k2 = 0.5 * (y[3] - y[1]);
    double k3 = 1.0 * (y[3] - y[2]);
    if (solve(k1) || solve(k2) || solve(k3))
      puts("Yes");
    else
      puts("No");
  }
  return 0;
}
