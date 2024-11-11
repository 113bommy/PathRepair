#include <bits/stdc++.h>
double E = 1e-9;
using namespace std;
int mabs(int a) {
  if (a < 0)
    return -a;
  else
    return a;
}
int main() {
  int n;
  double res = 0;
  scanf("%d", &n);
  vector<int> r(n);
  for (int i = 0; i < n; ++i) scanf("%d", &r[i]);
  sort(r.begin(), r.end());
  bool f = 1;
  for (int i = n - 1; i >= 0; i--) {
    if (i - 1 >= 0 && f) {
      res += (r[i] * r[i] - r[i - 1] * r[i - 1]);
      f = 0;
    } else if (f) {
      res += (r[i] * r[i]);
      f = 0;
    } else
      f = 1;
  }
  cout.precision(25);
  res *= 3.14159265358979323846264338327950288419716939937510;
  cout << res << endl;
  return 0;
}
