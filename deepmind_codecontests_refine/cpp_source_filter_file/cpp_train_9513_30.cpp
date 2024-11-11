#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  if (m == 3) {
    if (n == 3) {
      cout << 0 << ' ' << 0 << "\n";
      cout << 0 << ' ' << 1 << "\n";
      cout << 1 << ' ' << 0 << "\n";
      return 0;
    } else if (n == 4) {
      cout << 0 << ' ' << 0 << "\n";
      cout << 0 << ' ' << 10 << "\n";
      cout << 10 << ' ' << 0 << "\n";
      cout << 1 << ' ' << 1 << "\n";
      return 0;
    } else if (n >= 5) {
      cout << -1;
      return 0;
    }
  }
  int x = 100000000;
  for (int i = 0; i < m; i++) cout << i << " " << (i * i + x) << "\n";
  for (int i = 0; i < n - m; i++) cout << i << " " << (-i * i - x) << "\n";
  return 0;
}
