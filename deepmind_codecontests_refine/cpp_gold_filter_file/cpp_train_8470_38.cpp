#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  while (n <= 70000) {
    ++n;
    int x = n;
    int a[10] = {0};
    for (int i = 0; i < 4; i++) {
      int m = x % 10;
      ++a[m];
      x = x / 10;
    }
    int count = 0;
    for (int i = 0; i < 10; i++) {
      if (a[i] == 1) ++count;
    }
    if (count == 4) {
      cout << n;
      break;
    }
  }
}
