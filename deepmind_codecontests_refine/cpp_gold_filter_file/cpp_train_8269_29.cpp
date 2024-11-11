#include <bits/stdc++.h>
using namespace std;
long long n, mx = -1e9, i, k, ans, a, b, c, p[1000001], p1[1000001], p2[100001],
             l = 1, m, z, mn, x, j;
bool f;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> p[i] >> p1[i];
    p2[p[i]] = p1[i];
  }
  sort(p, p + n);
  mn = p2[p[n - 1]];
  for (i = n - 2; i >= 0; i--) {
    if (p2[p[i]] > mn) {
      f = 1;
      break;
    }
    mn = min(p2[p[i]], mn);
  }
  cout << (f ? "Happy Alex" : "Poor Alex");
  return 0;
}
