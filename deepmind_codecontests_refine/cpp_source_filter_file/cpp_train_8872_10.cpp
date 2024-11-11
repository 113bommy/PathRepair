#include <bits/stdc++.h>
using namespace std;
int fact(int m) {
  int factorial = 1, i;
  for (int i = 1; i <= m; ++i) {
    factorial *= i;
  }
  return factorial;
}
int main() {
  int n, k[10000], l[10000], i;
  while (scanf("%d", &n) != EOF) {
    for (i = 0; i < n; i++) {
      scanf("%d", &k[i]);
      l[i] = fact(k[i]);
    }
    for (i = 0; i < n; i++) {
      cout << l[i] << endl;
    }
  }
}
