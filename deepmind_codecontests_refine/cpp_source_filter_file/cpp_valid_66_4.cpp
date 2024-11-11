#include <bits/stdc++.h>
using namespace std;
int main() {
  int x;
  cin >> x;
  for (int i = 0; i < x; i++) {
    int cas;
    int count = 0;
    cin >> cas;
    for (int j = 1;; j++) {
      if (j % 10 != 3 && (j % 3 != 0)) {
        count++;
      }
      if (cas == count) {
        cout << j;
        break;
      }
    }
  }
  return 0;
}
