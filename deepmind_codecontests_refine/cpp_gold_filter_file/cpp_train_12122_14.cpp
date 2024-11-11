#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int ar1[n], ar2[m], ar3[n];
  for (int i = 1; i <= n; i++) {
    ar1[i] = 0;
  }
  for (int i = 1; i <= m; i++) {
    cin >> ar2[i];
    int j = ar2[i];
    while (ar1[j] != 1 && j <= n) {
      ar1[j] = 1;
      ar3[j] = ar2[i];
      j++;
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << ar3[i] << " ";
  }
  return 0;
}
