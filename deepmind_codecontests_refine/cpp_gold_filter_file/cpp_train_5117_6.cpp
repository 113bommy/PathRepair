#include <bits/stdc++.h>
using namespace std;
int a[128], t;
string s;
int main() {
  a['A'] = a['E'] = a['F'] = a['H'] = a['I'] = a['K'] = a['L'] = a['M'] =
      a['N'] = a['T'] = a['V'] = a['W'] = a['X'] = a['Y'] = a['Z'] = 1;
  cin >> s;
  for (int i = 0; i < s.size(); ++i) t += a[s[i]];
  cout << (t == 0 || t == s.size() ? "YES" : "NO");
}
