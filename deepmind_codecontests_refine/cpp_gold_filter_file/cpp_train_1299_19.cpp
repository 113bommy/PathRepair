#include <bits/stdc++.h>
using namespace std;
int main() {
  long long result = 0;
  int x, y;
  cin >> x >> y;
  int col[1000];
  int row[1000];
  for (int i = 0; i < y; i++) {
    col[i] = 0;
  }
  for (int i = 0; i < x; i++) {
    row[i] = 0;
  }
  wstring table[1000];
  for (int i = 0; i < x; i++) {
    wstring line;
    wcin >> line;
    table[i] = line;
    for (int e = 0; e < y; e++) {
      if (line[e] == '*') {
        col[e] += 1;
        row[i] += 1;
      }
    }
  }
  for (int i = 0; i < x; i++) {
    for (int e = 0; e < y; e++) {
      if (table[i][e] == '*') {
        result += (row[i] - 1) * (col[e] - 1);
      }
    }
  }
  cout << result;
  return 0;
}
