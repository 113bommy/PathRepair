#include <bits/stdc++.h>
using namespace std;
struct team {
  int p, t;
} a[51];
int n, k;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> k;
  for (int i = 0; i < n; ++i) cin >> a[i].p >> a[i].t;
  sort(a, a + n, [](const team& x, const team& y) {
    return (x.p > y.p || (x.p == y.p && x.t < y.t));
  });
  int res = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i].t == a[k].t && a[i].p == a[k].p) ++res;
  }
  cout << res;
  return 0;
}
