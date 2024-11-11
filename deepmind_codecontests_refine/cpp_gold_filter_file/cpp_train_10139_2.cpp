#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int mod = m - n % m;
  for (int i = 0; i < m; i++) {
    if (i >= mod) {
      cout << n / m + 1 << " ";
    } else
      cout << n / m << " ";
  }
  return 0;
}
