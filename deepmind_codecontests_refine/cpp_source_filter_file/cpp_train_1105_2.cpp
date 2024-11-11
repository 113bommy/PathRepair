#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 19;
int n, p[N];
bool b[100];
int main() {
  cin >> n;
  p[0] = 0;
  for (int i = 1; i <= n; i++) {
    fill(b, b + 100, 0);
    for (int j = 2; 2 * n - j * j + j > 0; j++) {
      int y = (2 * n - j * j + j);
      if (y % (2 * j) == 0) {
        int c = p[y / (2 * j) - 1] ^ p[y / (2 * j) + j - 1];
        b[c] = 1;
        if (i == n && c == 0) {
          cout << j << endl;
          return 0;
        }
      }
    }
    for (int j = 0; j < 100; j++)
      if (!b[j]) {
        p[i] = p[i - 1] ^ j;
        break;
      }
  }
  cout << -1 << endl;
  return 0;
}
