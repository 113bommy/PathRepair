#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  while (cin >> n) {
    char scheme[100 + 10] = {};
    for (int i = 0; i < n; i++) cin >> scheme[i];
    int begin, length, cur = 1;
    bool good = false;
    for (int i = 0; i < n - 4; i++) {
      if (scheme[i] == '*') {
        begin = i;
        for (int j = 1; j <= n / 4; j++) {
          length = j;
          int cur0 = 1;
          while (scheme[begin + length * cur0] == '*') {
            cur++;
            if (cur == 5) {
              good = true;
              break;
            }
            cur0++;
          }
          if (good)
            break;
          else
            cur = 1;
        }
      }
      if (good) break;
    }
    if (good)
      cout << "yes" << endl;
    else
      cout << "no" << endl;
  }
  return 0;
}
