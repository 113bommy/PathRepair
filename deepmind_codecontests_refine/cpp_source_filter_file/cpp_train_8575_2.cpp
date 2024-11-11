#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, x, n, m;
  while (~scanf("%d%d", &n, &m)) {
    if (m > 26 || m > n || n > 1 && m == 1) {
      cout << -1;
    } else {
      x = m - 2;
      for (i = 1; i <= n - x; i++) {
        if (i % 2)
          cout << 'a';
        else
          cout << 'b';
      }
      for (; i <= n; i++) {
        printf("%c", i - n + x + 'b');
      }
    }
    cout << endl;
  }
  return 0;
}
