#include <bits/stdc++.h>
int main() {
  char table[100][100];
  int a{1}, b{1}, c{1};
  for (int i = 1; i < 4; i++) {
    for (int j = 1; j < 4; j++) {
      std::cin >> table[i][j];
    }
  }
  for (int i = 1; i < 4; i++) {
    for (int j = 1; j < 4; j++) {
      if (table[i][j] == '>') {
        if (table[i][j - 1] == 'A') {
          a++;
        }
        if (table[i][j - 1] == 'B') {
          b++;
        }
        if (table[i][j - 1] == 'C') {
          c++;
        }
      }
      if (table[i][j] == '<') {
        if (table[i][j + 1] == 'A') {
          a++;
        }
        if (table[i][j + 1] == 'B') {
          b++;
        }
        if (table[i][j + 1] == 'C') {
          c++;
        }
      }
    }
  }
  if (a > c && a > b && b > c) {
    std::cout << "CBA";
    return 0;
  }
  if (a > c && a > b && c > b) {
    std::cout << "BCA";
    return 0;
  }
  if (b > c && b > a && c > a) {
    std::cout << "ACB";
    return 0;
  }
  if (b > c && b > a && a > c) {
    std::cout << "CAB";
    return 0;
  }
  if (c > a && c > a && a > b) {
    std::cout << "BAC";
    return 0;
  }
  if (c > b && b > a && b > a) {
    std::cout << "ABC";
    return 0;
  } else {
    std::cout << "Impossible";
  }
  return 0;
}
