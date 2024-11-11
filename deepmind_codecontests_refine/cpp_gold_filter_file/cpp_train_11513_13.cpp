#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int m = n - k;
  int b = 97;
  bool g = 1;
  for (int i = 1; i <= k; i++) {
    if (i <= n) {
      printf("%c", b);
      b++;
    } else
      break;
  }
  int d = 97;
  int e = d + 1;
  for (int i = 0; i < m; i++) {
    if (g) {
      printf("%c", d);
      g = 0;
    } else {
      printf("%c", e);
      g = 1;
    }
  }
}
