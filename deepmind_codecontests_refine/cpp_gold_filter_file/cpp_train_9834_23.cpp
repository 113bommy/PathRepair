#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  while (cin >> n) {
    cout << "+------------------------+" << endl;
    int row[3];
    if (n == 0) {
      cout << "|#.#.#.#.#.#.#.#.#.#.#.|D|)" << endl;
      cout << "|#.#.#.#.#.#.#.#.#.#.#.|.|" << endl;
      cout << "|#.......................|" << endl;
      cout << "|#.#.#.#.#.#.#.#.#.#.#.|.|)" << endl;
    } else if (n == 1) {
      cout << "|O.#.#.#.#.#.#.#.#.#.#.|D|)" << endl;
      cout << "|#.#.#.#.#.#.#.#.#.#.#.|.|" << endl;
      cout << "|#.......................|" << endl;
      cout << "|#.#.#.#.#.#.#.#.#.#.#.|.|)" << endl;
    } else if (n == 2) {
      cout << "|O.#.#.#.#.#.#.#.#.#.#.|D|)" << endl;
      cout << "|O.#.#.#.#.#.#.#.#.#.#.|.|" << endl;
      cout << "|#.......................|" << endl;
      cout << "|#.#.#.#.#.#.#.#.#.#.#.|.|)" << endl;
    } else if (n == 3) {
      cout << "|O.#.#.#.#.#.#.#.#.#.#.|D|)" << endl;
      cout << "|O.#.#.#.#.#.#.#.#.#.#.|.|" << endl;
      cout << "|O.......................|" << endl;
      cout << "|#.#.#.#.#.#.#.#.#.#.#.|.|)" << endl;
    } else if (n == 4) {
      cout << "|O.#.#.#.#.#.#.#.#.#.#.|D|)" << endl;
      cout << "|O.#.#.#.#.#.#.#.#.#.#.|.|" << endl;
      cout << "|O.......................|" << endl;
      cout << "|O.#.#.#.#.#.#.#.#.#.#.|.|)" << endl;
    } else {
      int k = (n - 4) % 3;
      for (int i = 0; i < 3; ++i) {
        row[i] = (n - 4) / 3;
      }
      for (int i = 0; i < k; ++i) {
        row[i]++;
      }
      cout << "|O.";
      for (int i = 0; i < 10; ++i) {
        if (i < row[0])
          cout << "O.";
        else
          cout << "#.";
      }
      cout << "|D|)" << endl;
      cout << "|O.";
      for (int i = 0; i < 10; ++i) {
        if (i < row[1])
          cout << "O.";
        else
          cout << "#.";
      }
      cout << "|.|" << endl;
      cout << "|O.......................|" << endl;
      cout << "|O.";
      for (int i = 0; i < 10; ++i) {
        if (i < row[2])
          cout << "O.";
        else
          cout << "#.";
      }
      cout << "|.|)" << endl;
    }
    cout << "+------------------------+" << endl;
  }
  return 0;
}
