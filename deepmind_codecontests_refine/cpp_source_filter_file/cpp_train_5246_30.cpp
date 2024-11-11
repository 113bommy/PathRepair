#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int l_cnt = 0, r_cnt = 0;
  for (int i = 0; i < int(n); i++) {
    if (s[i] == 'L')
      l_cnt++;
    else if (s[i] == 'R')
      r_cnt++;
  }
  int l = 0, r = 0;
  if (r_cnt == 0) {
    for (int i = n - 1; i >= 0; i--) {
      if (s[i] != '.') {
        l = i;
        break;
      }
    }
    for (int i = 0; i < n; i++) {
      if (s[i] != '.') {
        r = i;
        break;
      }
    }
    r--;
  } else if (l_cnt == 0) {
    for (int i = 0; i < n; i++) {
      if (s[i] != '.') {
        l = i;
        break;
      }
    }
    for (int i = n - 1; i >= 0; i--) {
      if (s[i] != '.') {
        r = i;
        break;
      }
    }
    r++;
  } else {
    for (int i = 0; i < n; i++) {
      if (s[i] == 'L') {
        r = i;
        break;
      }
    }
    for (int i = 0; i < n; i++) {
      if (s[i] == 'R') {
        l = i;
        break;
      }
    }
    r++;
  }
  cout << l + 1 << " " << r + 1 << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
