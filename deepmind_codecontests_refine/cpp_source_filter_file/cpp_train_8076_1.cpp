#include <bits/stdc++.h>
using namespace std;
double q3 = sqrt(3);
double r;
bool judge(double x, double y) {
  double xx, yy;
  xx = x + 1.0;
  yy = y;
  if (xx * xx + yy * yy - r * r > 0) return false;
  xx = x + 0.5;
  yy = y + 0.5 * q3;
  if (xx * xx + yy * yy - r * r > 0) return false;
  return true;
}
long long ans[1000010];
int main() {
  int n;
  cin >> n;
  r = 1.0 * n;
  int now = (r - 0.5 * q3) / q3;
  int i = 0;
  double x, y;
  while (now >= 0) {
    if (i & 1) {
      x = 1.5 * i;
      y = q3 * now + 0.5 * q3;
    } else {
      x = 1.5 * i;
      y = q3 * now;
    }
    if (judge(x, y)) {
      ans[i] = ++now;
      i++;
    } else
      now--;
  }
  long long mm = 0;
  mm += 2 * ans[0] - 1;
  for (int j = 1; j < i; j++) {
    if (j & 1)
      mm += 4 * ans[j];
    else
      mm += 4 * ans[j] - 2;
  }
  cout << mm << endl;
  return 0;
}
