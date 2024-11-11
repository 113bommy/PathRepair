#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  cout << n + (m - 1) << "\n";
  int p = 1, j = 1, k = 1;
  for (int i = 0; i < n + (m - 1); i++) {
    if (i < m) {
      cout << p << " " << j << "\n";
      j++;
    } else {
      p++;
      cout << p << " " << k << "\n";
    }
  }
}
