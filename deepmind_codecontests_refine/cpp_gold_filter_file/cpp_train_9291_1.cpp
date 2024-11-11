#include <bits/stdc++.h>
using namespace std;
int board[330][330];
long long f(int n) {
  long long mxr, mnr, mxc, mnc;
  mxr = mxc = 0;
  mnr = mnc = 1e18;
  for (int i = 0; i < n; i++) {
    long long s = 0;
    for (int j = 0; j < n; j++) s += board[i][j];
    mxr = max(mxr, s);
    mnr = min(mnr, s);
  }
  for (int i = 0; i < n; i++) {
    long long s = 0;
    for (int j = 0; j < n; j++) s += board[j][i];
    mxc = max(mxc, s);
    mnc = min(mnc, s);
  }
  return (mxr - mnr) * (mxr - mnr) + (mxc - mnc) * (mxc - mnc);
}
void solve() {
  int n, k;
  cin >> n >> k;
  memset(board, 0, sizeof(board));
  if (k != 0) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      int y = i, x = 0;
      for (int j = 0; j < n; j++) {
        board[y][x] = 1;
        y++, x++;
        y %= n, x %= n;
        if (++cnt == k) break;
      }
      if (cnt == k) break;
    }
  }
  cout << f(n) << '\n';
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) cout << board[i][j];
    cout << '\n';
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
