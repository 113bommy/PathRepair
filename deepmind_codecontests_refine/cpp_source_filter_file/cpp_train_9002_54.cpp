#include <bits/stdc++.h>
using namespace std;
const int MaxN = 1e5 + 17;
int n, x, y, x2, y2, a[500][500], Sum;
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> x >> y >> x2 >> y2;
    for (int j = x; j <= x2; ++j)
      for (int k = y; k <= y2; ++k) a[j][k]++;
  }
  for (int i = 1; i <= 5; ++i)
    for (int j = 1; j <= 5; ++j) Sum += a[i][j];
  cout << Sum;
  return 0;
}
