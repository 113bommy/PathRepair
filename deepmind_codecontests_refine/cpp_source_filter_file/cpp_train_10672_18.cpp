#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  double ans = 0, total;
  int l[100005], r[100005], p, p1, p2;
  cin >> n >> p;
  for (int i = 0; i < n; ++i) {
    cin >> l[i] >> r[i];
  }
  for (int i = 0; i < n; ++i) {
    p1 = (r[i] - l[i] + 1) - (r[i] / p - (l[i] - 1) / p);
    p2 = (r[(i + 1) % n] - l[(i + 1) % n] + 1) -
         (r[(i + 1) % n] / p - (l[(i + 1) % n] - 1) / p);
    total = ((r[i] - l[i] + 1) * (r[(i + 1) % n] - l[(i + 1) % n] + 1));
    ans += 2000 * (1 - ((p1 * p2) / total));
  }
  printf("%.10lf\n", ans);
}
