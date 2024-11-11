#include <bits/stdc++.h>
using namespace std;
const int N = 1007, K = 1007, INF = LONG_MAX;
int n, a[150000], i, j, m[150000];
int main() {
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  int mx = 0;
  for (i = n - 1; i >= 0; i--) {
    mx = max(mx, a[i]);
    m[i] = mx;
  }
  for (i = 0; i < n; i++) {
    cout << max(0, m[i + 1] - a[i] + 1);
  }
}
