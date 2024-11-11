#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, sum, i, j;
  cin >> n;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++) {
      cin >> x;
      if (i == (n + 1) / 2 || j == (n + 1) / 2 || i == j || (i + j) == (n + 1))
        sum = sum + x;
    }
  cout << sum;
  return 0;
}
