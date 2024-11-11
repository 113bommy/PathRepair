#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[26] = {0};
  string s;
  cin >> s;
  int l = s.length();
  for (int i = 0; i < l; i++) {
    a[s[i] - 'a']++;
  }
  int cn = a['n' - 'a'] / 2;
  int ce = a['e' - 'a'] / 3;
  int ct = a['t' - 'a'];
  int ci = a['i' - 'a'];
  int ans = min(min(ci, ct), min(cn, ce));
  cout << ans;
}
