#include <bits/stdc++.h>
using namespace std;
using namespace std;
int main() {
  int x[31][31];
  int n;
  cin >> n;
  int col[n];
  int row[n];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> x[i][j];
    }
  }
  int sumr = 0;
  int sumc = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      sumc += x[i][j];
      sumr += x[j][i];
    }
    col[i] = sumc;
    row[i] = sumr;
    sumc = 0;
    sumr = 0;
  }
  int c = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (col[i] > row[j]) {
        c++;
      }
    }
  }
  cout << c << endl;
  return 0;
}
