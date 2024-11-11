#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long data[n + 1][n + 1];
  for (int i = 0; i <= n; ++i) {
    data[i][0] = 1;
    data[i][i] = 1;
    for (int j = 1; j < i; ++j) {
      data[i][j] = data[i - 1][j - 1] + data[i - 1][j];
    }
  }
  cout << data[n][5] + data[n][6] + data[n][7];
}
