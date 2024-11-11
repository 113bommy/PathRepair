#include <bits/stdc++.h>
using namespace std;
long long n, m, ans;
string s;
long long b[100005];
long long a[100005];
int main() {
  cin >> s;
  int v = 0, h = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'R') {
      h++;
    }
    if (s[i] == 'L') {
      h--;
    }
    if (s[i] == 'U') {
      v++;
    }
    if (s[i] == 'D') {
      v--;
    }
  }
  if (v < 0) v *= -1;
  if (h < 0) h *= -1;
  if (s.length() % 2 == 1) {
    cout << -1;
  } else {
    ans = min(v, h) + (max(v, h) - min(v, h)) / 2;
    cout << ans << endl;
  }
  return 0;
}
