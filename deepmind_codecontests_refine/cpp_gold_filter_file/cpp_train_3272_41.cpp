#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[101];
  int i, j, n, t;
  cin >> n;
  getchar();
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (i = 0; i < n - 1; i++) {
    for (j = 1; j < n - i; j++) {
      if (a[j] < a[j - 1]) {
        t = a[j];
        a[j] = a[j - 1];
        a[j - 1] = t;
      }
    }
  }
  for (i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  return 0;
}
