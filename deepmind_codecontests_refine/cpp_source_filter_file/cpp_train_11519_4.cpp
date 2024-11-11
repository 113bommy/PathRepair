#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
int main() {
  int n, m, k, t, mn = 1000000;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    cin >> t;
    if (i % 2 == 0) mn = min(mn, t);
  }
  if (n % 2 == 0)
    cout << 0;
  else
    cout << min(mn, m / ((n + 1) / 2) * k);
  return 0;
}
