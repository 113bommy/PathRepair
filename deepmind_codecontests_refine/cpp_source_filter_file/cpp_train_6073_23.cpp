#include <bits/stdc++.h>
const double eps = 1e-10;
using namespace std;
int dblcmp(double x) {
  if (fabs(x) < eps) return 0;
  return x > 0 ? 1 : -1;
}
bool pri[2000000];
int p[100000], e, ans[100000];
int main() {
  int i, j, k, n;
  int a, b;
  string s;
  int t;
  memset(pri, 0, sizeof(pri));
  e = 0;
  for (i = 2; i < 2000000; ++i)
    if (!pri[i]) {
      p[e++] = i;
      for (j = i * 2; j < 2000000; j += i) pri[j] = 1;
    }
  k = 0;
  for (i = 0; i < e; ++i) {
    a = 0;
    t = p[i];
    while (t) {
      a = a * 10 + t % 10;
      t /= 10;
    }
    if (a < 2000000 && !pri[a] && a != p[i]) ans[k++] = p[i];
  }
  while (cin >> a) {
    cout << ans[a - 1] << endl;
  }
  return 0;
}
