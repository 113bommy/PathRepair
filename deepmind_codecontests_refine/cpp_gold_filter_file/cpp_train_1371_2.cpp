#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  int x = 1, y = n, i = 1, j = m;
  int cnt = 2 * m;
  while (x < y) {
    if (cnt % 2 == 0) {
      cout << x << " " << i++ << '\n';
    } else
      cout << y << " " << j-- << '\n';
    cnt--;
    if (cnt == 0) {
      cnt = 2 * m;
      x++;
      y--;
      i = 1, j = m;
    }
  }
  int a = 1, b = m;
  for (int i = 1; i <= m; i++) {
    if (i % 2 == 1 && n % 2) {
      cout << x << " " << a++ << '\n';
    }
    if (i % 2 == 0 && n % 2) cout << x << " " << b-- << '\n';
  }
}
