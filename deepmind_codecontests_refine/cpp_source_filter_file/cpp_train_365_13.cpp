#include <bits/stdc++.h>
using namespace std;
long long mydiv(long long a, long long b) {
  if (b < 0) {
    a = -a;
    b = -b;
  }
  if (a >= 0)
    return a / b;
  else
    return -((-a + b - 1) / b);
}
int main() {
  int n;
  scanf("%d", &n);
  vector<int> vx(n), vy(n);
  for (int i = 0; i < n; ++i) scanf("%d%d", &vx[i], &vy[i]);
  for (int i = 1; i < n; ++i) vy[i] -= vy[0];
  vy[0] = 0;
  if (vy[2] < 0) {
    for (int i = 0; i < n; ++i) vy[i] = -vy[i];
  }
  if (vy[0] > vy[1]) {
    swap(vx[0], vx[1]);
    swap(vy[0], vy[1]);
    reverse(vx.begin() + 2, vx.end());
    reverse(vy.begin() + 2, vy.end());
  }
  vx.push_back(vx[0]);
  vy.push_back(vy[0]);
  int lb = vx[0];
  int ub = vx[1];
  for (int i = 2; i <= n; ++i) {
    if (vy[i] < vy[i - 1]) {
      long long lb1 = vx[i] - mydiv((long long)vy[i] * (vx[i] - vx[i - 1]),
                                    vy[i] - vy[i - 1]);
      if (lb1 > ub) lb1 = ub + 1;
      lb = max(lb, (int)lb1);
    } else if (vy[i] > vy[i - 1]) {
      long long ub1 = vx[i] - mydiv((long long)vy[i] * (vx[i] - vx[i - 1]) +
                                        (vy[i] - vy[i - 1] - 1),
                                    vy[i] - vy[i - 1]);
      if (ub1 < lb) ub1 = lb - 1;
      ub = min(ub, (int)ub1);
    } else if (vx[i] > vx[i - 1])
      ub = lb - 1;
  }
  printf("%d\n", max(0, ub - lb + 1));
  return 0;
}
