#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, t, k, x;
  cin >> t;
  for (i = 0; i < t; i++) {
    cin >> k;
    int a[1000];
    int b = 1;
    for (x = 1; x < 1667; x++) {
      if (!((x % 3 == 0) || (x % 10 == 3))) {
        a[b] = x;
        b++;
      } else {
        continue;
      }
    }
    cout << a[k];
  }
  return 0;
}
