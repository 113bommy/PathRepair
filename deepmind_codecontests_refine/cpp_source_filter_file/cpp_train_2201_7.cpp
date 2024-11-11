#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
bool check(char a, char b, char c) {
  int ans = (a - 48) * 100 + (b - 48) * 10 + (c - 48);
  return (ans % 8 == 0 ? true : false);
}
void solve() {
  int h1, m1, h2, m2;
  char c;
  cin >> h1 >> c >> m1 >> h2 >> c >> m2;
  int a = ((h2 * 60 - m2) + (h1 * 60 + m1)) / 2;
  int h = a / 60, m = a % 60;
  if (h < 10) cout << '0';
  cout << h << ':';
  if (m < 10) cout << '0';
  cout << m;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  while (t--) solve();
}
