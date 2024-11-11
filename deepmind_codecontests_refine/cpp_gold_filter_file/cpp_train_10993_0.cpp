#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i;
  cin >> n;
  i = 1;
  while (n > 0) {
    if (n > i * 5) {
      n = n - i * 5;
    } else {
      if (n - i > 0) {
        n = n - i;
        if (n - i > 0) {
          n = n - i;
          if (n - i > 0) {
            n = n - i;
            if (n - i > 0) {
              n = n - i;
              n = n - i;
              cout << "Howard";
            } else {
              n = n - i;
              cout << "Rajesh";
            }
          } else {
            n = n - i;
            cout << "Penny";
          }
        } else {
          n = n - i;
          cout << "Leonard";
        }
      } else {
        n = n - i;
        cout << "Sheldon";
      }
    }
    i = i * 2;
  }
  return 0;
}
