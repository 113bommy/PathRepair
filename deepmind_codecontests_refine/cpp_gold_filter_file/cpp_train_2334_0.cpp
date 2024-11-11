#include <bits/stdc++.h>
using namespace std;
int main() {
  int k;
  cin >> k;
  k *= 2;
  char a[4][4];
  int i, j;
  int b[9] = {0};
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      cin >> a[i][j];
      if (a[i][j] != '.') {
        b[a[i][j] - '1']++;
      }
    }
  }
  for (i = 0; i < 9; i++) {
    if (b[i] > k) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
  return 0;
}
