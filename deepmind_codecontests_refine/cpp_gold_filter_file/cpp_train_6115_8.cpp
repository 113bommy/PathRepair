#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int m, n;
  cin >> n;
  cin >> m;
  int a[n], b[m];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int j = 0; j < m; j++) {
    cin >> b[j];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i] == b[j]) {
        cout << a[i] << " ";
        break;
      }
    }
  }
  return 0;
}
