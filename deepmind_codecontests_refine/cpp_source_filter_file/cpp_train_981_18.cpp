#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, n, k;
  char c;
  cin >> n >> m >> k;
  int i, j;
  int* num = new int[m];
  for (i = 0; i < m; i++) num[i] = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      cin >> c;
      switch (c) {
        case 'L':
          if (j >= i) num[j - i]++;
          break;
        case 'R':
          if (i + j < m) num[i + j]++;
          break;
        case 'U':
          if (i > 1) num[j]++;
          break;
        case 'D':
          break;
      }
    }
  }
  for (i = 0; i < m - 1; i++) cout << num[i] << " ";
  cout << num[m - 1];
  return 0;
}
