#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  int n;
  int a[201][201];
  int b[200];
  int c[200][200];
  for (int k = 0; k < q; k++) {
    cin >> n;
    a[0][k] = n;
    for (int i = 1; i <= n; i++) {
      cin >> b[i];
    }
    for (int i = 1; i <= n; i++) {
      a[i][0] = i;
    }
    for (int j = 1; j <= 200; j++) {
      for (int i = 1; i <= n; i++) {
        a[b[i]][j] = a[i][j - 1];
      }
    }
    int i = 4;
    for (int i = 1; i <= n; i++) {
      int j = 1;
      while (a[i][0] != a[i][j]) {
        j++;
      }
      c[k][i] = j;
    }
  }
  for (int k = 0; k < q; k++) {
    for (int i = 1; i <= a[0][k]; i++) {
      cout << c[k][i] << " ";
    }
    cout << endl;
  }
  return 0;
}
