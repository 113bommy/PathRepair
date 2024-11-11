#include <bits/stdc++.h>
using namespace std;
struct pasager {
  int f, t;
} a[101];
int n, s, i, sol;
bool cmp(pasager a, pasager b) {
  if (a.f == b.f) return a.t < b.t;
  return a.f > b.f;
}
int main() {
  cin >> n >> a[0].f;
  for (i = 1; i <= n; i++) cin >> a[i].f >> a[i].t;
  sort(a + 1, a + n + 1, cmp);
  for (i = 1; i <= n; i++) {
    sol += a[i - 1].f - a[i].f;
    if (a[i].t > sol) sol += a[i].t - sol;
  }
  sol += a[n].f;
  cout << sol;
  return 0;
}
