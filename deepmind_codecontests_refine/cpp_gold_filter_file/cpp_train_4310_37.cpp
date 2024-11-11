#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, k, n, m;
  while (cin >> n >> k) {
    if (n * (n - 1) / 2 <= k) {
      puts("no solution");
    } else {
      for (i = 0; i < n; i++) printf("0 %d\n", i);
    }
  }
  return 0;
}
