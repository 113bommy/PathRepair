#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
long long a, b, c, d, n;
long long f(long long col) { return (col >= a) ? d : b; }
void solve() {
  cin >> a >> b >> c >> d >> n;
  vector<vector<char>> mat(max(b, d), vector<char>(a + c, '.'));
  long long col = 0, row = 0, del = 1;
  if (a % 2) {
    row = b - 1;
    del = -1;
  }
  char ch = 'a';
  for (long long i = 0; i < n; i++) {
    long long pts;
    cin >> pts;
    while (pts > 0) {
      mat[row][col] = ch;
      row += del;
      if (row < 0) {
        row++;
        del = 1;
        col++;
      } else if (row >= f(col)) {
        row--;
        col++;
        del = -1;
      }
      pts--;
    }
    ch++;
  }
  cout << "YES" << '\n';
  for (auto &x : mat) {
    for (auto &y : x) cout << y;
    cout << '\n';
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long t = 1;
  while (t--) solve();
  return 0;
}
