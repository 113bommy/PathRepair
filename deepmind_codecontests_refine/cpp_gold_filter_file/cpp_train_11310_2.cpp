#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  int n, m, k, curr = 0, result = 0;
  cin >> n >> m >> k;
  char sits[n][m];
  for (int i = 0; i < n; i++) {
    curr = 0;
    for (int j = 0; j < m; j++) {
      cin >> sits[i][j];
      if (sits[i][j] == '.')
        curr++;
      else
        curr = 0;
      if (curr == k) {
        result++;
        curr--;
      }
    }
  }
  if (k != 1) {
    for (int i = 0; i < m; i++) {
      curr = 0;
      for (int j = 0; j < n; j++) {
        if (sits[j][i] == '.')
          curr++;
        else
          curr = 0;
        if (curr == k) {
          result++;
          curr--;
        }
      }
    }
  }
  cout << result;
  return 0;
}
