#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int a[n], b[m];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  int i = 0, j = 0, sol = 0;
  while (j < m) {
    if (b[j] >= a[i]) {
      i++;
      j++;
    } else {
      j++;
    }
  }
  cout << n - i << endl;
  return 0;
}
