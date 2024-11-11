#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, i, c, j;
  cin >> a >> b;
  for (i = a + 1;; i++) {
    c = 0;
    for (j = 2; j <= i; j++) {
      if (i % j == 0) c++;
    }
    if (c == 1 && i == b) {
      cout << "YES";
      break;
    } else if (c == 1 && i != b) {
      cout << "NO";
      break;
    }
  }
  return 0;
}
