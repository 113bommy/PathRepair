#include <bits/stdc++.h>
using namespace std;
map<char, int> a;
string s;
long long ans, i, l;
int main() {
  cin >> s;
  l = s.size();
  for (i = 0; i < l; i++) a[s[i]]++;
  for (i = 0; i < l; i++) ans += a[s[i]];
  cout << ans << endl;
}
