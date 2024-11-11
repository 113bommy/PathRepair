#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int *a, *b;
  a = new int[n];
  b = new int[m];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i] == b[j]) {
        cout << a[i] << " ";
      }
    }
  }
  cout << endl;
  return 0;
}
