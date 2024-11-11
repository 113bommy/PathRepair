#include <bits/stdc++.h>
using namespace std;
int main() {
  int c, d, n, m, k;
  cin >> c >> d >> n >> m >> k;
  int x = n * m - k;
  int y = (x + n - 1) / n;
  int mn = 1e6 + 1;
  for (int i = 0; i <= y; i++) {
    int x1 = i * c;
    int y1 = max(0, x - i * n) * d;
    mn = min(mn, x1 + y1);
  }
  cout << mn << endl;
  return 0;
}
