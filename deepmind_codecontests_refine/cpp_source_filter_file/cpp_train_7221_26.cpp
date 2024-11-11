#include <bits/stdc++.h>
using namespace std;
int main() {
  int z = 0;
  for (int i = 1; i <= 5; i++) {
    for (int j = 0; j <= 5; j++) {
      cin >> z;
      if (z == 1) {
        cout << abs(i - 3) + abs(j - 3) << endl;
      }
    }
  }
  return 0;
}
