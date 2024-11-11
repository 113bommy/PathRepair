#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  int ar[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      ar[i][j] = 0;
    }
  }
  int x = 0, p = k;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (k >= 1 && x == 0) {
        ar[i][i] = 1;
        k--;
        x = 1;
      }
      if (k > 1 && ar[i][j] == 0) {
        ar[i][j] = 1;
        ar[j][i] = 1;
        k -= 2;
      }
    }
    x = 0;
  }
  if (p >= n * n) {
    cout << "-1";
  } else {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << ar[i][j] << " ";
      }
      cout << "\n";
    }
  }
}
