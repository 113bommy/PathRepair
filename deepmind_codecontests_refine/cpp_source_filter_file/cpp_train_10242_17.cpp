#include <bits/stdc++.h>
using namespace std;
void swap(long long *a, long long *b) {
  long long temp = *a;
  *a = *b;
  *b = temp;
}
int toggle(int n) {
  if (n == 1)
    return 0;
  else
    return 1;
}
int main() {
  long long t = 1;
  while (t--) {
    int a[3][3];
    int b[5][5];
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        b[i][j] = 1;
      }
    }
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        cin >> a[i][j];
        if (a[i][j] % 2 == 0)
          a[i][j] = 0;
        else
          a[i][j] = 1;
      }
    }
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (a[i][j] == 1) {
          b[i + 1][j + 2] = toggle(b[i + 1][j + 2]);
          b[i + 1][j] = toggle(b[i + 1][j]);
          b[i + 2][j + 1] = toggle(b[i + 2][j + 1]);
          b[i][j + 1] = toggle(b[i][j + 1]);
          b[i + 1][j + 1] = toggle(b[i + 1][j + 1]);
        }
      }
    }
    for (int i = 1; i <= 3; i++) {
      for (int j = 1; j <= 3; j++) {
        cout << b[i][j] << " ";
      }
      cout << endl;
    }
  }
}
