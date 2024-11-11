#include <bits/stdc++.h>
using namespace std;
const int mxN = 50;
void solve() {
  string f, m, s;
  cin >> f >> m >> s;
  string r = "rock", p = "paper", sc = "scissors";
  if (f == r && m == sc && s == sc) {
    cout << 'F';
    return;
  }
  if (f == p && m == r && s == r) {
    cout << 'F';
    return;
  }
  if (f == sc && m == p && s == p) {
    cout << 'F';
    return;
  }
  if (m == r && f == sc && s == sc) {
    cout << 'M';
    return;
  }
  if (m == p && f == r && s == r) {
    cout << 'M';
    return;
  }
  if (m == sc && f == p && s == p) {
    cout << 'M';
    return;
  }
  if (s == r && f == sc && m == sc) {
    cout << 'M';
    return;
  }
  if (s == p && f == r && m == r) {
    cout << 'M';
    return;
  }
  if (s == sc && f == p && m == p) {
    cout << 'M';
    return;
  } else
    puts("?");
}
int main() {
  int t = 1;
  for (long long cas = 1; cas <= t; cas++) {
    solve();
  }
  return 0;
}
