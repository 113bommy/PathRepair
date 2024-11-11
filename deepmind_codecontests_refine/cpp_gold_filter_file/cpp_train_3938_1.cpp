#include <bits/stdc++.h>
using namespace std;
void err() {
  cout << -1 << '\n';
  exit(0);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int n = s.length();
  s = '$' + s;
  if (s[1] == '0' || s[n - 1] == '0' || s[n] == '1') {
    err();
  }
  for (int i = 1; i <= n / 2; i++) {
    if (s[i] != s[n - i]) {
      err();
    }
  }
  int par = 1;
  for (int i = 2; i <= n; i++) {
    cout << par << ' ' << i << '\n';
    if (s[i - 1] == '1') {
      par = i;
    }
  }
  return 0;
}