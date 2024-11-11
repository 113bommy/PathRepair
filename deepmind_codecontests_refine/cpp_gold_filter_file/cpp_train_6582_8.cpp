#include <bits/stdc++.h>
using namespace std;
long long cab(int n, int m) {
  long long z = 1;
  for (int i = 0; i < m; i++) z = z * (n - i) / (i + 1);
  return z;
}
int main() {
  int n, m, x;
  cin >> n >> m >> x;
  cout << cab(n + m, x) - cab(n, x) - cab(m, x) - cab(n, 1) * cab(m, x - 1) -
              cab(n, 2) * cab(m, x - 2) - cab(n, 3) * cab(m, x - 3);
  return 0;
}
