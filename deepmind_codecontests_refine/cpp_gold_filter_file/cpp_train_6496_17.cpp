#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int *a = new int[m];
  for (int i = 0; i < m; i++) {
    cin >> a[i];
  }
  long long M = 0;
  for (int i = 0; i < m; i++) {
    if (i == 0) {
      M += a[i] - 1;
    } else {
      if (a[i] < a[i - 1]) {
        M += n - a[i - 1] + a[i];
      } else {
        M += a[i] - a[i - 1];
      }
    }
  }
  cout << M << endl;
  return 0;
}
