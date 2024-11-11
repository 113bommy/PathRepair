#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[101][101];
  int n;
  for (int i = 1; i < 10; i++)
    for (int j = 1; j < 10; j++) a[i][j] = 0;
  cin >> n;
  while (n) {
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    for (int i = x1; i <= x2; i++)
      for (int j = y1; j <= y2; j++) a[i][j] = a[i][j] + 1;
    n--;
  }
  int sum = 0;
  for (int i = 1; i < 101; i++)
    for (int j = 1; j < 101; j++) sum = sum + a[i][j];
  cout << endl << sum;
  return 0;
}
