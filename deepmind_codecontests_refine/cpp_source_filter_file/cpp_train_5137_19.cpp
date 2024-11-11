#include <bits/stdc++.h>
using namespace std;
string a, b;
bool div(string s, int l) {
  for (int i = 0; i < a.length(); i++) {
    if (a[i % l] != s[i]) return false;
  }
  return true;
}
int main() {
  int ans = 0, x, y;
  cin >> a >> b;
  x = a.length();
  y = b.length();
  int sz = min(x, y);
  for (int i = 1; i <= sz; i++) {
    if (x % i == 0 && y % i == 0) {
      if (div(a, i) && div(b, i)) ans++;
    }
  }
  cout << ans;
  return 0;
}
