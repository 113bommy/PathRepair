#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n;
  cin >> m;
  vector<int> row(m);
  vector<int> column(n);
  if (m == 1) {
    row[0] = 1;
  } else if (m == 2) {
    row[0] = 3;
    row[1] = 4;
  }
  if (n == 1) {
    column[0] = 1;
  } else if (n == 2) {
    column[0] = 3;
    column[1] = 4;
  }
  for (int i = 0; i < m - 1 && m > 2; i++) {
    row[i] = 2;
  }
  for (int i = 0; i < n - 1 && n > 2; i++) {
    column[i] = 2;
  }
  if (m > 2) {
    row[m - 1] = m - 2;
  }
  if (n > 2) {
    column[n - 1] = n - 2;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << column[i] * row[j] << " ";
    }
    cout << endl;
  }
}
