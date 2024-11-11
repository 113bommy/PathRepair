#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  int mas[51][51];
  cin >> a >> b;
  bool isGood = 0;
  for (int i = 1; i <= a; i++)
    for (int j = 1; j <= b; j++) {
      cin >> mas[i][j];
      if (mas[i][j] == 1 && (i == 1 || j == 1 || i == a || j == b)) isGood = 1;
    }
  if (isGood) {
    cout << 2;
  } else
    cout << 4;
  return 0;
}
