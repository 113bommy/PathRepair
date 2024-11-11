#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> x(n);
  for (int i = 0; i < n; ++i) scanf("%d", &x[i]);
  for (int i = 0; i < n; ++i) {
    int mn = 2e9 + 7;
    if (i > 0) mn = min(mn, x[i] - x[i - 1]);
    if (i < n - 1) mn = min(mn, x[i + 1] - x[i]);
    int mx = -2e9 - 7;
    if (i == 0 || i == n - 1)
      mx = x[n - 1] - x[0];
    else
      mx = max(x[i] - x[0], x[n - 1] - x[i]);
    printf("%d %d\n", mn, mx);
  }
  return 0;
  return 0;
}
