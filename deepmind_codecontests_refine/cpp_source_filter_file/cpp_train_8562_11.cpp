#include <bits/stdc++.h>
using namespace std;
int main() {
  string line;
  int count = 0;
  cin >> line;
  int row = 0;
  for (int i = 0; i < line.length(); ++i) {
    if (i == 0) {
      count++;
      row++;
    } else if (line[i - 1] != line[i]) {
      count++;
      row = 1;
    } else {
      if (row < 5)
        row++;
      else {
        row = 0;
        count++;
      }
    }
  }
  cout << count << endl;
  return 0;
}
