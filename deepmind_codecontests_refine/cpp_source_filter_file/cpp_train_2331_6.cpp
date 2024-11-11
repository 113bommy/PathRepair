#include <bits/stdc++.h>
using namespace std;
const int maxint = -1u >> 1;
const double eps = 1e-8;
int sgn(const double &x) { return (x > eps) - (x < -eps); }
int n;
vector<int> a, b;
int main() {
  while (scanf("%d", &n) == 1) {
    a.clear();
    b.clear();
    for (int i = 0; i < (n * 2 - 1); ++i) {
      int tmp;
      scanf("%d", &tmp);
      if (tmp >= 0)
        a.push_back(tmp);
      else
        b.push_back(tmp);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ans = 0;
    if (n % 2 == 1 || ((int)(b).size()) % 2 == 0) {
      for (int i = 0; i < (((int)(a).size())); ++i) ans += a[i];
      for (int i = 0; i < (((int)(b).size())); ++i) ans += abs(b[i]);
    } else {
      int h = b[((int)(b).size()) - 1];
      if (((int)(a).size()) != 0) {
        h += a[0];
        h = abs(h);
      }
      for (int i = 0; i < (((int)(b).size()) - 1); ++i) ans += abs(b[i]);
      for (int i = (1); i <= (((int)(a).size())); ++i) ans += abs(a[i]);
      ans += h;
    }
    printf("%d\n", ans);
  }
  return 0;
}
