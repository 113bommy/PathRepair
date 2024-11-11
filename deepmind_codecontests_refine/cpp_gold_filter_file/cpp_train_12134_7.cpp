#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, max = 0, z = 1, c[100000];
  cin >> a;
  for (int i = 0; i < a; i++) {
    cin >> c[i];
    if (i != 0) {
      if (c[i] > c[i - 1]) {
        z++;
      } else {
        if (z > max) {
          max = z;
        }
        z = 1;
      }
    }
  }
  if (z > max) max = z;
  cout << max;
  return 0;
}
