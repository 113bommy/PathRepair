#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int i, j, k, l, m, n, t;
  cin >> n;
  char a[2];
  a[0] = 'W';
  a[1] = 'B';
  l = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (j == 0) {
        k = l;
      }
      cout << a[k] << " ";
      k = 1 - k;
    }
    l = 1 - l;
    cout << endl;
  }
}
