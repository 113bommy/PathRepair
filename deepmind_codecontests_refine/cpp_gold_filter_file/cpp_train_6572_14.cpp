#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, count = 0;
  cin >> n;
  char x[n + 1][n + 1];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> x[i][j];
    }
  }
  for (int i = 2; i < n; i++) {
    for (int j = 2; j < n; j++) {
      if (x[i][j] == 'X' && x[i - 1][j + 1] == 'X' && x[i + 1][j - 1] == 'X' &&
          x[i + 1][j + 1] == 'X' && x[i - 1][j - 1] == 'X') {
        count++;
      }
    }
  }
  cout << count << endl;
}
