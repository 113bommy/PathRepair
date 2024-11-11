#include <bits/stdc++.h>
using namespace std;
int n, m, a, b[110000], p[110000];
int ans;
bool check(int);
int main() {
  cin >> n >> m >> a;
  for (int i = 0; i < n; ++i) cin >> b[i];
  for (int i = 0; i < m; ++i) cin >> p[i];
  sort(b, b + n);
  sort(p, p + m);
  int l = 0, r = min(n, m);
  while (l < r) {
    int mid = (l + r) / 2 + 1;
    if (check(mid))
      l = mid;
    else
      r = mid - 1;
  }
  cout << l << ' ';
  for (int i = 0; i < l; ++i) ans += p[i];
  cout << (a >= ans ? 0 : ans - a) << endl;
  return 0;
}
bool check(int x) {
  int rem = a;
  for (int i = 0; i < x; ++i) {
    if (b[n - x + i] < p[i]) {
      rem = rem - (p[i] - b[n - x + i]);
      if (rem < 0) return false;
    }
  }
  return true;
}
