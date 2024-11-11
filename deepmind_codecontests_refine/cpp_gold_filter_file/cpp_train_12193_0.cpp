#include <bits/stdc++.h>
using namespace std;
const long long MAX = 3e5 + 6;
long long x[MAX], y[MAX];
long long n, k;
signed main() {
  long long u = 0;
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  for (long long i = 1; i <= n; i++) {
    cin >> x[i];
  }
  for (long long i = 1; i <= n; i++) {
    cin >> y[i];
  }
  for (long long i = 1; i <= n; i++) {
    if (x[i] > y[i]) {
      if (k * (y[i] + 1) < x[i]) {
        cout << "NO";
        return 0;
      } else {
        if (x[i + 1] >= y[i + 1]) x[i + 1] += max(x[i] - k * y[i], u);
      }
    } else {
      if (k * (x[i] + 1) < y[i]) {
        cout << "NO";
        return 0;
      } else {
        if (y[i + 1] >= x[i + 1]) y[i + 1] += max(y[i] - k * x[i], u);
      }
    }
  }
  cout << "YES";
}
