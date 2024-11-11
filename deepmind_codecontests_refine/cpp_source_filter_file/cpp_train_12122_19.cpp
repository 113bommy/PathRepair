#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  cin >> n >> m;
  long long a[n], b[m], i, j;
  for (i = 0; i < m; i++) {
    cin >> b[i];
  }
  for (i = 0; i < n; i++) {
    a[i] = -1;
  }
  for (i = 1; i < m; i++) {
    for (j = b[i] - 1; j < n; j++) {
      if (a[j] == -1) {
        a[j] = b[i];
      }
    }
  }
  for (i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  return 0;
}
