#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  long long int c[n][m];
  long long int min[n];
  for (int i = 0; i < n; i++) {
    min[i] = 10000000000;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> c[i][j];
      if (c[i][j] < min[i]) {
        min[i] = c[i][j];
      }
    }
  }
  long long int answer = -1;
  for (int i = 0; i < n; i++) {
    if (answer < min[i]) {
      answer = min[i];
    }
  }
  cout << answer << endl;
  return 0;
}
