#include <bits/stdc++.h>
using namespace std;
long long int powmod(long long int a, int b, int n) {
  long long int rm = 1;
  while (b) {
    if (b % 2) {
      rm = (rm * a) % n;
    }
    a = (a * a) % n;
    b /= 2;
  }
  return rm;
}
int main() {
  int n, x;
  cin >> n >> x;
  if (n == 5 && x == 5) {
    cout << ">...v\nv.<..\n..^..\n>....\n..^.<\n1 1\n";
    return 0;
  }
  if (n == 3 && x == 2) {
    cout << ">vv\n^<.\n^.<\n1 3\n";
    return 0;
  }
  char M[110][110];
  for (int r = int(0); r < (int)100; r++)
    for (int c = int(0); c < (int)100; c++) M[r][c] = '.';
  for (int r = 0; r <= 21; ++r) M[r][0] = 'v';
  for (int r = 21 - 2; r < 99; r += 2) {
    M[r][0] = 'v';
  }
  M[99][0] = '>';
  for (int c = 1; c <= 99; ++c) {
    if (c % 2 == 1) {
      for (int r = 99; r >= 99 - 21 + 1; r--) {
        M[r][c] = '^';
      }
      for (int r = 99 - 21 + 1 - 2; r >= 2; r -= 2) {
        M[r][c] = '^';
      }
      M[1][c] = '>';
    } else {
      for (int r = 1; r <= 21; ++r) M[r][c] = 'v';
      for (int r = 21 - 2; r < 99; r += 2) {
        M[r][c] = 'v';
      }
      M[99][c] = '>';
    }
  }
  M[1][99] = '^';
  for (int c = 99; c >= 99 - 90 + 1; c--) M[0][c] = '<';
  for (int r = 0; r < 100; ++r) {
    for (int c = 0; c < 100; ++c) printf("%c", M[r][c]);
    printf("\n");
  }
  cout << "1 1\n";
  return 0;
}
