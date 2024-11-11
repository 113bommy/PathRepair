#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cout.precision(20);
  int k;
  cin >> k;
  vector<vector<int> > result(100, vector<int>(100, 0));
  int n = 3;
  int total = 1;
  for (int i = 4; i <= 100 && total; ++i) {
    int v = (i - 1) * (i - 2) / 2;
    if (total + v > k) {
      n = i - 1;
      break;
    }
    total += v;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      result[i][j] = 1;
      result[j][i] = 1;
    }
  }
  while (k - total > 0) {
    int x = int(pow(double(2 * (k - total)), 0.5));
    while (x * (x + 1) > 2 * (k - total)) {
      x--;
    }
    for (int i = 0; i <= x; ++i) {
      result[i][n] = 1;
      result[n][i] = 1;
    }
    total += x * (x + 1) / 2;
    n++;
  }
  cout << n << endl;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << result[i][j];
    }
    cout << endl;
  }
  return 0;
}
