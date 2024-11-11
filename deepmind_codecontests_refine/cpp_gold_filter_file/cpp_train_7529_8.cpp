#include <bits/stdc++.h>
using namespace std;
int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  if (n == 1) {
    int tmp;
    cin >> tmp;
    cout << tmp;
    exit(0);
  }
  vector<vector<int> > field(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) cin >> field[i][j];
  }
  int middle = (n - 1) / 2;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += field[middle][i];
    ans += field[i][middle];
    ans += field[i][i];
    ans += field[n - 1 - i][i];
  }
  ans -= field[middle][middle] * 3;
  cout << ans;
}
