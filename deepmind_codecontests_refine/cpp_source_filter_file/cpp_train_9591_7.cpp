#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, i, j = 0, k = 0, k1 = 0, z = 0, x1 = 0, ar[1234], x = 0;
  cin >> a >> b;
  for (i = 1; i <= a; i++) {
    cin >> ar[i];
    if (ar[i] == 1) {
      k++;
    } else {
      x++;
    }
  }
  x1 = x;
  k1 = k;
  for (i = 1; i <= a; i++) {
    for (j = i; j <= a; j = j + b) {
      if (ar[j] == 1) {
        k1--;
      } else {
        x1--;
      }
    }
    z = max(z, abs(k1 - x1));
    k1 = k;
    x1 = x;
  }
  cout << z << endl;
}
