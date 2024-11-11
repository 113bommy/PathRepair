#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int d[4];
  int b;
  int k;
  int c;
  cin >> n;
  for (int i = n + 1; i < 2020; i++) {
    b = i;
    k = 0;
    while (b > 0) {
      d[k] = b % 10;
      b /= 10;
      k++;
    }
    c = 0;
    for (int j = 0; j < 4; j++) {
      for (int l = j + 1; l < 4; l++) {
        if (d[j] == d[l]) {
          c = 1;
        }
      }
    }
    if (c == 0) {
      cout << i << endl;
      break;
    }
  }
  return 0;
}
