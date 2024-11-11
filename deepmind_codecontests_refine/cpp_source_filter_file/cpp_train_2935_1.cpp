#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a;
  cin >> a;
  char b[a][a];
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < a; j++) {
      if (i % 2 == 0) {
        if (j % 2 == 0) {
          b[i][j] = 'W';
        } else
          b[i][j] = 'B';
      } else {
        if (j % 2 != 0) {
          b[i][j] = 'W';
        } else
          b[i][j] = 'B';
      }
    }
  }
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < a; j++) {
      cout << b[i][j] << " ";
    }
    cout << endl;
  }
}
