#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int main() {
  string s, p;
  cin >> s >> p;
  a[0] = 0;
  for (int i = 0; i < s.length(); ++i) {
    if (s[i] == '1') {
      a[i + 1] = a[i] + 1;
    } else
      a[i + 1] = a[i];
  }
  int ck = 0;
  for (int i = 0; i < p.length(); ++i) {
    if (p[i] == '1') ck++;
  }
  int ans = 0;
  int l = p.length();
  for (int i = 0; i < s.length() - p.length(); ++i) {
    int gg = a[i + l] - a[i] + ck;
    if (gg % 2 == 0) ans++;
  }
  cout << ans << endl;
}
