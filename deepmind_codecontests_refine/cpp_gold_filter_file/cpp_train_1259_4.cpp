#include <bits/stdc++.h>
using namespace std;
void fastio() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
bool chck(char c, char d) {
  char c1, c2, d1, d2;
  if (c == 'a')
    c1 = '#';
  else
    c1 = char(c - 1);
  if (d == 'a')
    d1 = '$';
  else
    d1 = char(d - 1);
  if (c == 'z')
    c2 = '#';
  else
    c2 = char(c + 1);
  if (d == 'z')
    d2 = '$';
  else
    d2 = char(d + 1);
  if (c1 == d1 || c1 == d2) return true;
  if (c2 == d1 || c2 == d2) return true;
  return false;
}
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  bool f = true;
  for (int i = 0; i < n / 2; i++) {
    if (chck(s[i], s[n - 1 - i]))
      continue;
    else {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
}
int main() {
  fastio();
  int t;
  t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
