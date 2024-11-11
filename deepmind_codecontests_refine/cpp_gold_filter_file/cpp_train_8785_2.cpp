#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j, k, a, g = 1;
  cin >> n;
  j = n * n;
  for (i = 1; i <= n; i++) {
    a = g;
    for (k = 1; k <= n / 2; k++) {
      cout << a << " ";
      a++;
    }
    for (k = 1; k <= n / 2; k++) {
      a--;
      cout << j - a + 1 << " ";
    }
    g += n / 2;
    cout << endl;
  }
  return 0;
}
