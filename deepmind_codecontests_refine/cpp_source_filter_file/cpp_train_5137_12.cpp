#include <bits/stdc++.h>
using namespace std;
map<string, int> c;
int main() {
  int l1, l2, f, ans = 0;
  string s1, s2;
  cin >> s1 >> s2;
  l1 = s1.length();
  l2 = s2.length();
  for (int i = 1; i <= min(l1, l2); i++)
    if (l1 % i == 0 && l2 % i == 0) {
      f = 0;
      c.clear();
      for (int j = 0; j < l1; j += i) c[s1.substr(j, i)]++;
      if (c[s1.substr(0, i)] == l1 / i) f++;
      c.clear();
      for (int j = 0; j < l2; j += i) c[s2.substr(j, i)]++;
      if (c[s2.substr(0, i)] == l2 / i) f++;
      if (f == 2) ans++;
    }
  cout << ans << "\n";
  return 0;
}
