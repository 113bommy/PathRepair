#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k = 0;
  cin >> n >> m;
  int a[n];
  int b[m];
  int c[10];
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i] == b[j]) {
        c[k] = a[i];
        k++;
        break;
      }
    }
  }
  for (int i = 0; i < k; i++) cout << c[i] << " ";
}
