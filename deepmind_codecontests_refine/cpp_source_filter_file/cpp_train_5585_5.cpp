#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 7;
int n;
long double u, e[MAX];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> u;
  for (int i = 1; i <= n; ++i) {
    cin >> e[i];
  }
  long double res = -1;
  for (int i = 1; i < n - 1; ++i) {
    long double ei = e[i];
    long double ej = e[i + 1];
    int l = i + 2, r = n;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (e[mid] - ei > u) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    if (r != i + 1) {
      long double val = (e[r] - ej) / (e[r] - ei);
      res = max(res, val);
    }
  }
  cout << fixed << setprecision(6) << res << "\n";
  return 0;
}
