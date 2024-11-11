#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int q = 0, ones = 0, zeros = 0;
  for (int i = 0; i < k; i++) {
    int a = i;
    char c = s[i];
    while (a < n) {
      if (c == '0' && s[i] == '1') {
        cout << "NO" << endl;
        return;
      } else if (c == '1' && s[i] == '0') {
        cout << "NO" << endl;
        return;
      } else if (c == '?' && s[i] != '?') {
        c = s[i];
      }
      a += k;
    }
    if (c == '0')
      zeros++;
    else if (c == '1')
      ones++;
    else
      q++;
  }
  if (q == 0) {
    if (zeros == ones) {
      cout << "YES" << endl;
      return;
    } else
      cout << "NO" << endl;
  } else {
    if (zeros > k / 2 || ones > k / 2) {
      cout << "NO" << endl;
      return;
    }
    cout << "YES" << endl;
  }
}
int main() {
  int nt;
  cin >> nt;
  while (nt--) {
    solve();
  }
}
