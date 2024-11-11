#include <bits/stdc++.h>
using namespace std;
const char first[] = "input.txt";
const char fo[] = "";
string s[1005];
bool check[1005];
int m, n;
void input() {
  cin >> m >> n;
  for (int i = 0; i < m; ++i) cin >> s[i];
}
bool ok[1005];
bool incr(const int& c) {
  for (int i = 1; i < m; ++i)
    if (s[i][c] < s[i - 1][c] && !ok[i]) return false;
  return true;
}
void solve() {
  memset(ok, false, sizeof(ok));
  int res = 0;
  for (int j = 0; j < n; ++j) {
    if (incr(j)) {
      for (int i = 1; i < m; ++i) ok[i] |= (s[i][j] > s[i - 1][j]);
    } else
      ++res;
  }
  cout << res << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  input();
  solve();
  return 0;
}
