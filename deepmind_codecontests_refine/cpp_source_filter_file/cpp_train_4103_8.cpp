#include <bits/stdc++.h>
using namespace std;
int main() {
  int ma = 0, sum = 0, n, m, k, r, c, a[1000];
  cin >> n >> m >> k;
  for (int i = 1; i <= m; i++) {
    a[i] == k;
  }
  for (int i = 1; i <= n; i++) {
    cin >> r >> c;
    if (a[r] >= c) a[r] = c;
  }
  for (int i = 1; i <= m; i++) {
    sum += a[i];
  }
  if (sum <= k)
    cout << sum;
  else
    cout << k;
}
