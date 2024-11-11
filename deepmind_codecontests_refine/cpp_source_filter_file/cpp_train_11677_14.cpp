#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= (int)n / 2; ++i) {
    for (int j = 1; j <= (int)m; ++j) {
      cout << i << " " << j << '\n';
      cout << n - i + 1 << " " << j << '\n';
    }
  }
  if (n & 1) {
    for (int j = 1; j <= (int)m / 2; ++j) {
      cout << (n + 1) / 2 << " " << j << '\n';
      cout << (n + 1) / 2 << " " << m - j + 1 << '\n';
    }
    if (m & 1) cout << (n + 1) / 2 << " " << (m + 1) / 2 << '\n';
  }
}
