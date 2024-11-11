#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  while (cin >> n) {
    if (n > 0 && n < 10)
      cout << 1 << endl;
    else
      for (int i = 10; i < 1e9; i *= 10)
        if (n / i < 10) {
          cout << i - n % i << endl;
          break;
        }
  }
}
