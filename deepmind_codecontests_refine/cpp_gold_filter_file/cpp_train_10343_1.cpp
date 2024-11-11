#include <bits/stdc++.h>
using namespace std;
int main() {
  int x;
  while (cin >> x) {
    if (x == 3)
      cout << 5 << endl;
    else {
      int i = 1;
      while ((i * i + 1) / 2 < x) i += 2;
      cout << i << endl;
    }
  }
  return 0;
}
