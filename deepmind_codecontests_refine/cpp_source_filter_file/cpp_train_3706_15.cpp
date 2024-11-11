#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, i, c, j;
  cin >> a >> b;
  for (i = a + 1;; i++) {
    c = 0;
    for (j = 2; j <= a + 1; j++) {
      if (i % j == 0) c++;
    }
    if (c == 0 && i == b) {
      cout << "YES";
      break;
    } else if (c == 0 && i != b) {
      cout << "NO";
      break;
    }
  }
  return 0;
}
