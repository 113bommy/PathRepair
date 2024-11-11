#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, c, j;
  while (cin >> n) {
    for (i = 1; i <= n - 1; i++) {
      c = 0;
      for (j = i;; j += i) {
        c++;
        if (j > n)
          printf("%d%d ", j / n, j % n);
        else
          cout << j << " ";
        if (c == n - 1) break;
      }
      cout << endl;
    }
  }
  return 0;
}
