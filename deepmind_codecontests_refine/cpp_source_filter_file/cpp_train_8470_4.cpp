#include <bits/stdc++.h>
using namespace std;
int main() {
  bool outer = true;
  int n, a[4], temp, ans;
  cin >> n;
  while (outer) {
    bool isbreak = false;
    n++;
    temp = n;
    int i = 0, j, k;
    while (temp != 0) {
      a[i] = temp % 10;
      temp = temp / 10;
      i++;
    }
    for (j = 0; j < 3 && !isbreak; j++)
      for (k = j + 1; k < 4 && !isbreak; k++) {
        if (a[j] == a[k]) {
          isbreak = true;
          break;
        }
      }
    if (j == 2 && k == 3) {
      ans = n;
      outer = false;
    }
  }
  cout << ans;
  return 0;
}
