#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[100000], b[400000] = {0}, x, i, j, k = 0;
  cin >> n;
  x = n;
  for (i = 0; i < x; i++) {
    cin >> a[i];
    b[a[i]]++;
    if (a[i] == n) {
      for (j = n; j > 0; j--) {
        if (b[j] == 1) {
          cout << j << " ";
          k++;
        }
        if (b[j] == 0) {
          cout << endl;
          break;
        }
      }
    } else
      cout << endl;
    n = n - k;
    k = 0;
  }
}
