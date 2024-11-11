#include <bits/stdc++.h>
using namespace std;
char t[500010];
string s, ans;
int a[2], ne[500000];
int main() {
  cin >> s >> t + 1;
  int d = strlen(t + 1);
  for (int i = 0; i < s.size(); i++) a[s[i] - '0']++;
  for (int i = 2, j = 0; i <= d; i++) {
    while (j && t[i] != t[j + 1]) j = ne[j];
    if (t[i] == t[j + 1]) j++;
    ne[i] = j;
  }
  for (int i = 1; i <= d; i++) {
    if (a[0] == 0 || a[1] == 0) break;
    if (t[i] == '0')
      ans += "0", a[0]--;
    else if (t[i] == '1')
      ans += "1", a[1]--;
    if (i == d) i = ne[i];
  }
  cout << ans;
  while (a[0]--) cout << '0';
  while (a[1]--) cout << '1';
  return 0;
}
