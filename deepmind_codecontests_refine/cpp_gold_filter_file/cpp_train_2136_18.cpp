#include <bits/stdc++.h>
using namespace std;
int n, i, j, z[2234567], le;
string s, t;
void Z(string st) {
  int i, l = 0, r = 0;
  for (i = 1; i <= le; i++) {
    if (i <= r) {
      z[i] = min(z[i - l], r - i);
    }
    while (i + z[i] < le && st[z[i]] == st[i + z[i]]) z[i]++;
    if (i + z[i] > r) {
      l = i;
      r = i + z[i];
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  ;
  cin >> n >> s >> t;
  n--;
  for (i = 0; i < n; i++) {
    if (s[i] == 'W')
      s[i] = 'E';
    else if (s[i] == 'S')
      s[i] = 'N';
    else if (s[i] == 'E')
      s[i] = 'W';
    else if (s[i] == 'N')
      s[i] = 'S';
  }
  reverse(s.begin(), s.end());
  s = s + "#" + t;
  le = s.length();
  Z(s);
  for (i = n; i < le; i++) {
    if (i + z[i] >= le) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
  return 0;
}
