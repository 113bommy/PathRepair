#include <bits/stdc++.h>
using namespace std;
int n, a, b, c, i = 1, j;
int main() {
  cin >> n >> a >> b;
  if (2 * b < a || (a == 1 && n > 2)) return cout << -1, 0;
  if (a == b) {
    while (i < a) {
      cout << i << " " << i + 1 << endl;
      i++;
    }
    j = i;
    i++;
    while (i <= n) {
      cout << j << " " << i << endl;
      i++;
    }
    return 0;
  }
  while (i <= b) {
    cout << i << " " << i + 1 << "\n";
    i++;
  }
  if (i < n) {
    cout << 1 << " " << i + 1 << "\n";
    i++;
  }
  while (i <= a) {
    cout << i << " " << i + 1 << "\n";
    i++;
  }
  while (i < n) {
    cout << 1 << " " << i + 1 << "\n";
    i++;
  }
}
