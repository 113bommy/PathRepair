#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i = 1, g;
  cin >> n;
  if (n == 1) {
    cout << 1;
    return 0;
  }
  g = n;
  while (true) {
    if (n / (i * 2) > n / (i * 3)) {
      for (int j = 0; j < g - n / (i * 2); ++j) {
        cout << i << " ";
      }
      g -= n / (i * 2);
      if (n / (i * 2) == 1) {
        cout << i * 2;
        return 0;
      }
      i = i * 2;
    } else if (n / (i * 2) == n / (i * 3) && n / (i * 2) != 0) {
      for (int j = 0; j < g - 1; ++j) cout << i << " ";
      cout << i * 3;
      return 0;
    }
  }
}
