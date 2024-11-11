#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c = 0;
  cin >> n;
  int a[32][32];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int sumc = 0;
      int sumr = 0;
      for (int k = 0; k < n; k++) {
        sumr += a[k][j];
        sumc += a[i][k];
      }
      if (sumc > sumr) c++;
    }
  }
  cout << c;
  return 0;
}
