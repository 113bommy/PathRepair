#include <bits/stdc++.h>
using namespace std;
int main() {
  double n;
  int i, j;
  cin >> n;
  for (i = 1; i <= 10; i++)
    for (j = 1; j <= 10; j++)
      if (sqrt(i / 2.0 * i / 2.0 + j * j) * n - i * j / 2.0 <= 1e-6) {
        cout << i << ' ' << j << endl;
        return 0;
      }
}
