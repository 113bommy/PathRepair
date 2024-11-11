#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  while (cin >> n >> k) {
    int sum = n * (n - 1) / 2;
    if (n * k > sum)
      cout << -1 << endl;
    else {
      cout << n * k << endl;
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
          int x = (i + j) % n;
          if (x == n) x = n;
          printf("%d %d\n", i, x);
        }
      }
    }
  }
  return 0;
}
