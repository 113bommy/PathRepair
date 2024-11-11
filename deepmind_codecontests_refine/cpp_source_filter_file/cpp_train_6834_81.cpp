#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n > 34)
    cout << -1;
  else {
    while (n != 0) {
      if (n % 2 == 0) {
        cout << 8;
        n -= 2;
      } else {
        cout << 6;
        n -= 1;
      }
    }
  }
}
