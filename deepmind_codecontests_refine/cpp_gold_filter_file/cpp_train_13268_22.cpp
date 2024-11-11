#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int a[100][2];
  cin >> n;
  int k = 0;
  if (1 <= n && n <= 100) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 2; j++) {
        cin >> a[i][j];
      }
    }
    for (int i = 0; i < n; i++) {
      if (a[i][0] + 1 < a[i][1]) k++;
    }
    cout << k;
  }
  return 0;
}
