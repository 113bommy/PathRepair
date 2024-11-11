#include <bits/stdc++.h>
const double eps = 1e-10;
using namespace std;
int dblcmp(double x) {
  if (fabs(x) < eps) return 0;
  return x > 0 ? 1 : -1;
}
int ans[10];
int main() {
  int i, j, k, n;
  int a, b;
  string s;
  int t;
  ans[1] = 2;
  ans[2] = 2;
  ans[3] = 1;
  ans[4] = 3;
  ans[5] = 1;
  while (cin >> k) {
    cout << ans[k] << endl;
  }
  return 0;
}
