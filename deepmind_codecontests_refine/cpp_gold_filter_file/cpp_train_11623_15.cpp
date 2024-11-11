#include <bits/stdc++.h>
using namespace std;
int x, y;
int ap[100005], b[20000001] = {0};
int main() {
  int b1, b2, b3, m;
  cin >> b1 >> b2 >> b3 >> m;
  for (int i = 0; i < 250; i++) {
    for (int j = 0; j < 250; j++) {
      for (int h = 0; h < 250; h++) {
        if (i >= max(b1, m) && j >= max(b2, m) && h >= max(b3, m)) {
          if (i <= 2 * b1 && j <= 2 * b2 && h <= 2 * b3) {
            if (i > 2 * m && j > 2 * m) {
              if (h <= 2 * m) {
                if (i > j && j > h) {
                  cout << i << endl;
                  cout << j << endl;
                  cout << h << endl;
                  return 0;
                }
              }
            }
          }
        }
      }
    }
  }
  cout << -1 << endl;
  return 0;
}
