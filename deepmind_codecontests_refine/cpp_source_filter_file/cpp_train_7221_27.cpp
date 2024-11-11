#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, n;
  for (int i = 1; i <= 25; i++) {
    cin >> k;
    if (k == 1) {
      n = i;
    }
  }
  if (n == 1 || n == 5 || n == 21 || n == 25) {
    cout << 4;
  } else if (n == 8 || n == 18 || n == 12 || n == 14) {
    cout << 1;
  } else if (n == 13) {
    cout << 0;
  } else if (n == 7 || n == 9 || n == 17 || n == 19 || n == 3 || n == 11 ||
             n == 15 || n == 23) {
    cout << 1;
  } else {
    cout << 3;
  }
}
