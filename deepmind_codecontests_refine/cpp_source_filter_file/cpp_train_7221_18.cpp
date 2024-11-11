#include <bits/stdc++.h>
using namespace std;
int main() {
  int x = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> x;
      if (x == 1) {
        cout << abs(i - 3) + abs(j - 3);
      }
    }
  }
  return 0;
}
