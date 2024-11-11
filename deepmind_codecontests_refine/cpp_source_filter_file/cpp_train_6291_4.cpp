#include <bits/stdc++.h>
using namespace std;
int main() {
  int p = 0, k[100], ch = 0, m[100][100], min_hui = 500000, i, j;
  cin >> p;
  for (i = 0; i < p; i++) {
    cin >> k[i];
  }
  for (i = 0; i < p; i++) {
    ch = 0;
    for (j = 0; j < k[i]; j++) {
      cin >> m[i][j];
      ch += m[i][j] * 5 + 15;
    }
    if (min_hui > ch) {
      min_hui = ch;
    }
    cout << min_hui << endl;
  }
  return 0;
}
