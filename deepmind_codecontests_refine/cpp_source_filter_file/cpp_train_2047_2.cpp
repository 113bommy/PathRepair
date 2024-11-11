#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int n, m;
  long long int k;
  cin >> n >> m >> k;
  if (k < n) {
    cout << 1 << ' ' << k + 1 << '\n';
    return 0;
  }
  long long int ans_col, ans_row;
  k -= n;
  long long int row = k / (m - 1);
  ans_row = n - row;
  if (row & 1)
    ans_col = m - k % (m - 1);
  else
    ans_col = k % (m - 1) + 2;
  cout << ans_row << ' ' << ans_col << '\n';
}
