#include <bits/stdc++.h>
using namespace std;
int main() {
  int x[1000][1000];
  int a = 0;
  int b = 0;
  for (int i = 1; i <= 5; i++) {
    for (int j = 1; j <= 5; j++) {
      cin >> x[i][j];
      if (x[i][j] == 1) {
        a = i;
        b = j;
      }
    }
  }
  cout << abs(a - 3) + (b - 3);
  return 0;
}
