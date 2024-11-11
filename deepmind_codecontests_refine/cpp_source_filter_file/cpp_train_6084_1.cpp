#include <bits/stdc++.h>
using namespace std;
int a[20];
int main() {
  a[0] = 1;
  a[1] = 2;
  a[2] = 3;
  for (int i = 3; i < 20; i++) {
    for (int j = a[i - 1] + 1;; j++) {
      a[i] = j;
      int ok = 1;
      for (int x = 0; x < i; x++) {
        for (int y = x + 1; y < i; y++) {
          for (int z = z + 1; z < i; z++) {
            if (a[x] + j == a[y] + a[z]) ok = 0;
          }
        }
      }
      if (ok) {
        break;
      }
    }
  }
  int n;
  while (cin >> n) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == j)
          cout << 0 << " ";
        else
          cout << a[i] + a[j] << " ";
      }
      cout << endl;
    }
  }
  return 0;
}
