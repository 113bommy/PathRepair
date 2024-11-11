#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m;
int main() {
  cin >> n >> m;
  int x = 1;
  int y = 1;
  for (int i = 1; i <= n / 2; i++) {
    for (int j = 1; j <= m; j++) {
      printf("%d %d\n", i, j);
      printf("%d %d\n", n - i + 1, m - j + 1);
    }
  }
  if (n % 2) {
    for (int j = 1; j <= m / 2; j++) {
      printf("%d %d\n", n / 2 + 1, j);
      printf("%d %d\n", n / 2 + 1, m - j + 1);
    }
    if (m % 2) printf("%d %d\n", n / 2 + 1, m / 2 + 1);
  }
}
