#include <bits/stdc++.h>
using namespace std;
bool dot = true, ff = 0, ss = 0;
int f = 0, s = 0, first = 0, second = 0;
int main() {
  char a[3][3];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> a[i][j];
      a[i][j] == 'X' ? f++ : 0;
      a[i][j] == '.' ? dot = 0 : 0;
      a[i][j] == '0' ? s++ : 0;
    }
  }
  if (a[0][0] == 'X' && a[0][1] == 'X' && a[0][2] == 'X') {
    first++;
  }
  if (a[1][0] == 'X' && a[1][1] == 'X' && a[1][2] == 'X') {
    first++;
  }
  if (a[2][0] == 'X' && a[2][1] == 'X' && a[2][2] == 'X') {
    first++;
  }
  if (a[0][0] == 'X' && a[1][0] == 'X' && a[2][0] == 'X') {
    first++;
  }
  if (a[0][1] == 'X' && a[1][1] == 'X' && a[2][1] == 'X') {
    first++;
  }
  if (a[0][2] == 'X' && a[1][2] == 'X' && a[2][2] == 'X') {
    first++;
  }
  if (a[0][0] == 'X' && a[1][1] == 'X' && a[2][2] == 'X') {
    first++;
  }
  if (a[0][0] == 'X' && a[0][1] == 'X' && a[0][2] == 'X') {
    first++;
  }
  if (a[0][0] == '0' && a[0][1] == '0' && a[0][2] == '0') {
    second++;
  }
  if (a[1][0] == '0' && a[1][1] == '0' && a[1][2] == '0') {
    second++;
  }
  if (a[2][0] == '0' && a[2][1] == '0' && a[2][2] == '0') {
    second++;
  }
  if (a[0][0] == '0' && a[1][0] == '0' && a[2][0] == '0') {
    second++;
  }
  if (a[0][1] == '0' && a[1][1] == '0' && a[2][1] == '0') {
    second++;
  }
  if (a[0][2] == '0' && a[1][2] == '0' && a[2][2] == '0') {
    second++;
  }
  if (a[0][0] == '0' && a[1][1] == '0' && a[2][2] == '0') {
    second++;
  }
  if (a[0][0] == '0' && a[0][1] == '0' && a[0][2] == '0') {
    second++;
  }
  if (f - s > 1 || f < s) {
    puts("illegal");
    return 0;
  }
  if (second && first) {
    puts("illegal");
    return 0;
  }
  if (f - s == 1 && first > 0) {
    puts("the first player won");
    return 0;
  }
  if (f == s && second > 0) {
    puts("the second player won");
    return 0;
  }
  if (dot && first + second == 0) {
    puts("draw");
    return 0;
  }
  if (first + second == 0) {
    if (f == s) {
      puts("first");
      return 0;
    }
    if (f - s == 1) {
      puts("second");
      return 0;
    }
  }
  puts("illegal");
}
