#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int a[maxn][maxn];
bool ok(int i, int j) {
  if (a[i][j] && a[i][j + 1] && a[i][j + 1] && a[i + 1][j + 1]) return 1;
  return 0;
}
int main() {
  long long n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < k; i++) {
    long long x, y;
    cin >> x >> y;
    a[x][y] = 1;
    if (ok(x - 1, y - 1) || ok(x - 1, y) || ok(x, y - 1) || ok(x, y)) {
      cout << i + 1 << endl;
      return 0;
    }
  }
  cout << 0 << endl;
}
