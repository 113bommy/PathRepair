#include <bits/stdc++.h>
int main() {
  int lines, min = INT_MAX, koliko = 0;
  std::cin >> lines;
  int niz[101][101];
  for (int i = 0; i < lines; i++) {
    int x;
    std::cin >> x;
    niz[i][0] = x;
  }
  for (int i = 0; i < lines; i++) {
    for (int j = 1; j <= niz[i][0]; j++) {
      int x;
      std::cin >> x;
      niz[i][j] = x;
      koliko += x * 5;
    }
    koliko += niz[i][0] * 15;
    if (koliko < min) min = koliko;
    koliko = 0;
  }
  std::cout << min << std::endl;
  return 0;
}
