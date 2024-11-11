#include <bits/stdc++.h>
using namespace std;
int main() {
  char bus[6][100] = {
      "+------------------------+",  "|#.#.#.#.#.#.#.#.#.#.#.|D|)",
      "|#.#.#.#.#.#.#.#.#.#.#.|.|",  "|#.......................|",
      "|#.#.#.#.#.#.#.#.#.#.#.|.|)", "+------------------------+"};
  int k;
  cin >> k;
  for (int col = 1; col <= 100; col++) {
    for (int row = 1; row <= 4; row++) {
      if (k != 0) {
        if (row == 3 && col == 1) {
          bus[row][col] = 'O';
          k--;
        }
        if (bus[row][col] == '#') {
          bus[row][col] = 'O';
          k--;
        }
      }
    }
  }
  for (int i = 0; i < 6; i++) cout << bus[i] << "\n";
  return 0;
}
