#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  while (cin >> n >> m) {
    if (n > m) swap(n, m);
    if (n == 1)
      printf("%d\n", m);
    else if (n == 2)
      printf("%d\n", 4 + ((m - 1) / 4) * 4 - (m % 4 == 1) * 2);
    else
      printf("%d\n", n * m - n * m / 2);
  }
}
