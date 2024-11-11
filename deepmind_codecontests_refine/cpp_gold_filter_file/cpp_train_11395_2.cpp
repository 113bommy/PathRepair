#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  if (n == 1 && m == 1) {
    cout << "1" << endl;
    return 0;
  }
  if (n == 1 && m <= 3) {
    cout << "-1" << endl;
    return 0;
  }
  if (m == 1 && n <= 3) {
    cout << "-1" << endl;
    return 0;
  }
  if (n == 2 && m == 2) {
    cout << "-1" << endl;
    return 0;
  }
  int f = (n * m + 1) / 2, s = n * m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i % 2 + j % 2 == 0 || i % 2 + j % 2 == 2) {
        cout << f << " ";
        f--;
      } else {
        cout << s << " ";
        s--;
      }
    }
    cout << endl;
  }
}
