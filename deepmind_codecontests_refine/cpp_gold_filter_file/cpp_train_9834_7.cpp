#include <bits/stdc++.h>
using namespace std;
int main() {
  string a[6];
  a[0] = "+------------------------+";
  a[1] = "|#.#.#.#.#.#.#.#.#.#.#.|D|)";
  a[2] = "|#.#.#.#.#.#.#.#.#.#.#.|.|";
  a[3] = "|#.......................|";
  a[4] = "|#.#.#.#.#.#.#.#.#.#.#.|.|)";
  a[5] = "+------------------------+";
  int k;
  cin >> k;
  for (int i = 1; i <= 4 && k; i++) {
    a[i][1] = 'O';
    k--;
  }
  for (int j = 3; k; j += 2) {
    for (int i = 1; i <= 4 && k; i++) {
      if (i == 3) continue;
      a[i][j] = 'O';
      k--;
    }
  }
  for (int i = 0; i <= 5; i++) cout << a[i] << endl;
  return 0;
}
