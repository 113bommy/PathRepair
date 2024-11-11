#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  if (n * m == 1) {
    cout << 1 << endl;
    return 0;
  }
  if (n * m <= 5) {
    cout << -1 << endl;
    return 0;
  }
  int a = 1, b = n * m / 2 + 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (!((i + j) & 1)) {
        cout << b << " \n"[j == m];
        b++;
      } else {
        cout << a << " \n"[j == m];
        a++;
      }
    }
  return 0;
}
