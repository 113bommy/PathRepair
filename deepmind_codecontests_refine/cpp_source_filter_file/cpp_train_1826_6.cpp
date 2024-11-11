#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, t = 1;
  cin >> n >> m;
  int a = 1, b = 2;
  for (int i = 0; i < m; i++) {
    if (t == 1) {
      if ((n * 2) + b > m) {
        i--;
      } else
        cout << (n * 2) + a << " ";
    } else if (t == 2) {
      cout << a << " ";
      a += 2;
    } else if (t == 3) {
      if ((n * 2) + b > m) {
        i--;
      } else
        cout << (n * 2) + b << " ";
    } else if (t == 4) {
      cout << b << " ";
      b += 2;
    }
    t++;
    if (t == 5) t = 1;
  }
  return 0;
}
