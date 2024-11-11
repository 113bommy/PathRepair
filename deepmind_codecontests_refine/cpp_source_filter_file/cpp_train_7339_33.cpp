#include <bits/stdc++.h>
using namespace std;
int n;
char a[100][100];
int main() {
  int n1 = 100;
  int n2 = 100;
  for (int i = 1; i <= 8; i++) {
    for (int g = 1; g <= 8; g++) {
      cin >> a[i][g];
    }
  }
  for (int g = 1; g <= 8; g++) {
    for (int i = 1; i <= 8; i++) {
      if (a[i][g] == 'B') break;
      if (a[i][g] == 'W') {
        n1 = min(n1, i - 1);
      }
    }
  }
  for (int g = 1; g <= 8; g++) {
    for (int i = 1; i <= 8; i++) {
      if (a[i][g] == 'W') break;
      if (a[i][g] == 'B') {
        n2 = min(n2, 8 - i);
      }
    }
  }
  if (n1 <= n2)
    cout << "A" << endl;
  else
    cout << "B" << endl;
}
