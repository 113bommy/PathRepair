#include <bits/stdc++.h>
using namespace std;
int x[2000000], p[100];
int main() {
  long long g, k, sum, r, m, fl;
  for (int i = 5; i < 1000000; i++) {
    g = i;
    r = 5;
    sum = 0;
    while (g / r != 0) {
      sum += g / r;
      r = r * r;
    }
    x[i] = sum;
  }
  while (cin >> m) {
    k = 0;
    for (int i = 0; i < 1000000; i++) {
      if (x[i] == m) {
        p[k] = i;
        k++;
      }
      if (x[i] > m) break;
    }
    if (k > 0) {
      cout << k << endl;
      for (int i = 0; i < k; i++) {
        cout << p[i] << " ";
      }
      cout << endl;
    } else {
      cout << 0 << endl;
    }
  }
  return 0;
}
