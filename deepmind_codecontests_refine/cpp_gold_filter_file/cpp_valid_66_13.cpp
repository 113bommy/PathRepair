#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, k, i = 1, j = 1, a[1000];
  while (i <= 1000) {
    if (j % 10 != 3 && j % 3 != 0) {
      a[i] = j;
      i++;
    }
    j++;
  }
  cin >> t;
  for (i = 0; i < t; i++) {
    cin >> k;
    cout << a[k] << endl;
  }
}
