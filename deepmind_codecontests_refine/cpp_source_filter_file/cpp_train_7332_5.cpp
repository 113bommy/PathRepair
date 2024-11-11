#include <bits/stdc++.h>
using namespace std;
struct dat {
  double r;
  int k;
};
bool cmp(dat a, dat b) { return a.r < b.r; }
int main() {
  int n, s, x, y, z;
  cin >> n >> s;
  dat a[n];
  for (int i = 0; i < n; i++) {
    cin >> x >> y >> z;
    a[i].r = sqrt(x * x + y * y);
    a[i].k = z;
  }
  sort(a, a + n, cmp);
  int p[n];
  for (int i = 0; i < n; i++) {
    p[i] = a[i].k;
  }
  for (int i = 1; i < n; i++) {
    p[i] += p[i - 1];
  }
  int inc = 1000000 - s;
  int ind = lower_bound(p, p + n, inc) - p;
  if (ind != n)
    cout << setprecision(6) << a[ind].r << endl;
  else
    cout << -1 << endl;
}
