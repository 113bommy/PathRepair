#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n > 36) {
    cout << -1;
  } else {
    while (n) {
      if (n == 1) {
        cout << 0;
        n--;
      } else {
        cout << 8;
        n -= 2;
      }
    }
  }
  return 0;
}
