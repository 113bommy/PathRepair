#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n], b[n], i, j;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = i + 1;
  }
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (a[j] > a[j + 1]) {
        swap(a[j], a[j + 1]);
        swap(b[j], b[j + 1]);
      }
    }
  }
  for (i = 0; i < n / 2; i++) {
    cout << b[i] << " " << b[n - i - 1] << endl;
  }
  return 0;
}
