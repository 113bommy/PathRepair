#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n == 0) {
    cout << 1;
  }
  if (n > 34) {
    cout << -1;
  } else {
    while (n > 0) {
      if (n == 1) {
        cout << 4;
        --n;
      } else {
        cout << 8;
        n -= 2;
      }
    }
  }
}
