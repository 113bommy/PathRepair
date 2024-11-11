#include <bits/stdc++.h>
using namespace std;
int n, u, a[100001];
int main() {
  cin >> n >> u;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  double mx = -1;
  for (int i = 1; i < n - 1; i++) {
    int l = i + 2;
    int r = n;
    while (l - r > 1) {
      int mid = (l + r) / 2;
      if (a[mid] - a[i] <= u) {
        l = mid;
      } else {
        r = mid;
      }
    }
    if (a[r] - a[i] <= u) {
      double i1 = a[i], j1 = a[i + 1], k = a[r];
      mx = max(mx, (k - j1) / (k - i1));
    } else if (a[l] - a[i] <= u) {
      double i1 = a[i], j1 = a[i + 1], k = a[l];
      mx = max(mx, (k - j1) / (k - i1));
    }
  }
  cout << fixed << setprecision(9) << mx;
}
