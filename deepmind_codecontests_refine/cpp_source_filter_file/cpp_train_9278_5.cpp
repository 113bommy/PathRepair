#include <bits/stdc++.h>
using namespace std;
int main() {
  int square, pos = 0, idx = 0, iter, value;
  bool keep = true;
  cin >> square;
  while (keep) {
    for (int i = 1; i <= 2; i++) {
      for (int j = 0; j < iter; j++) {
        if (idx == square - 1) {
          keep = false;
          cout << value;
        };
        idx++;
      }
      value++;
    }
    iter++;
  }
}
