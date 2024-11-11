#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  int window[110][110];
  int c = 0;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2 * m; j++) {
      cin >> window[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2 * m; j += 2) {
      if (window[i][j] || window[i][j + 1]) c++;
    }
  }
  cout << c;
  return 0;
}
