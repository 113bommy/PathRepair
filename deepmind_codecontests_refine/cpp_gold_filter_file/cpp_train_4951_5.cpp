#include <bits/stdc++.h>
using namespace std;
int a[50][50];
int x, y;
void f(int n) {
  int x2 = x + 1;
  int y2 = y - 1;
  if (y2 < 0 && x2 >= n) {
    y2 = y + 1;
    x2 = x;
  } else if (x2 >= n)
    x2 = 0;
  else if (y2 < 0)
    y2 = n - 1;
  if (a[y2][x2] != 0) {
    y2 = y + 1;
    x2 = x;
  }
  y = y2;
  x = x2;
}
int main() {
  int n;
  cin >> n;
  x = n / 2;
  y = 0;
  for (int sum = 1; sum <= n * n; sum++) {
    a[y][x] = sum;
    f(n);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << a[i][j] << ' ';
    }
    cout << endl;
  }
  return 0;
}
