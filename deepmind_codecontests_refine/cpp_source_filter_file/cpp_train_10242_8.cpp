#include <bits/stdc++.h>
using namespace std;
void print(int a, int b, int c, int d, int e) {
  if ((a + b + c + d + e) % 2) {
    cout << 0;
  } else
    cout << 1;
}
int main() {
  int m[3][3];
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      cin >> m[i][j];
    }
  }
  print(0, 0, m[0][0], m[0][1], m[1][0]);
  print(0, m[0][0], m[0][1], m[0][2], m[1][1]);
  print(0, 0, m[0][2], m[0][1], m[1][2]);
  cout << endl;
  print(0, m[0][0], m[2][0], m[1][1], m[1][1]);
  print(m[0][1], m[1][2], m[2][1], m[1][0], m[1][1]);
  print(0, m[0][2], m[2][2], m[1][1], m[1][2]);
  cout << endl;
  print(0, 0, m[2][0], m[2][1], m[1][0]);
  print(0, m[2][1], m[2][0], m[2][2], m[1][1]);
  print(0, 0, m[2][2], m[2][1], m[1][2]);
  cout << endl;
  return 0;
}
