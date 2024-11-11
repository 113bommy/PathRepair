#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, t;
  cin >> n >> m >> t;
  long long arr[31][31];
  for (int i = 0; i <= 30; i++) {
    for (int j = 0; j <= i; j++) {
      if (j == 0 || i == j)
        arr[i][j] = 1;
      else
        arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
    }
  }
  long long sum = 0;
  for (int i = 4; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (i + j == t) sum += arr[n][i] * arr[m][j];
    }
  }
  cout << sum << endl;
  cin >> n;
  return 0;
}
