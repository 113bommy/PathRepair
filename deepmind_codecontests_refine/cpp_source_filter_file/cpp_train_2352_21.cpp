#include <bits/stdc++.h>
using namespace std;
const int nmax = 100011;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  int r = 1e9;
  for (int i = 1; i <= n; ++i) {
    int a;
    cin >> a;
    if (i != m && a <= k) r = min(r, abs(m - i) * 10);
  }
  cout << r;
}
