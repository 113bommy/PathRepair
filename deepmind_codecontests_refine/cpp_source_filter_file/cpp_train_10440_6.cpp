#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  while (cin >> n >> m) {
    if (n == 1 || m == 1) {
      printf("%d\n", m + n - 1);
      continue;
    }
    if (n == 2 || m == 2) {
      int k = 0;
      if ((m + n - 2) % 4 == 1) k = 2;
      int ct = (m + n - 2) / 2;
      ct = ((ct + 1) / 2) * 4;
      printf("%d\n", ct);
      continue;
    }
    printf("%d\n", ((n + 1) / 2) * ((m + 1) / 2) + (n / 2) * (m / 2));
  }
}
