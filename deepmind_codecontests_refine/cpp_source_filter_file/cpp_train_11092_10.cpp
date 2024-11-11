#include <bits/stdc++.h>
using namespace std;
long long maxint = 1e9 + 7;
long long n;
string st;
void openFile() { freopen("inp.txt", "r", stdin); }
void solve() {
  cin >> n;
  cin.ignore(1);
  cin >> st;
  long long px = -1;
  long long res = maxint, x;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (st[i] == 'R') {
      px = x;
    } else {
      if (px > 0) res = min(res, (x - px) / 2);
    }
  }
  res == maxint ? cout << -1 : cout << res;
}
int main() {
  ios::sync_with_stdio(false);
  int ntest;
  solve();
  return 0;
}
