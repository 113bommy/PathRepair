#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<int> row(n + 1, 1), col(n + 1, 1);
  for (int i = 1; i <= m; i++) {
    int c, r;
    cin >> c >> r;
    row[r] = 0;
    col[c] = 0;
  }
  int count = 0;
  for (int i = 2; i <= n - 1; i++) {
    if (2 * i - 1 == n) {
      count += (row[i] * col[i]);
      break;
    }
    if (i * 2 > n) break;
    count += (row[i] + col[i] + col[n - i + 1] + row[n - i + 1]);
  }
  cout << count;
  return 0;
}
