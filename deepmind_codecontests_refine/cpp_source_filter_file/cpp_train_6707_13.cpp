#include <bits/stdc++.h>
using namespace std;
int f[150], i, minn;
string s;
int main() {
  cin >> s;
  for (i = 0; i < s.size(); ++i) f[s[i] - 'a']++;
  minn = min((f['n' - 'a'] + f['n' - 'a'] / 3) / 3, f['e' - 'a'] / 3);
  minn = min(minn, min(f['i' - 'a'], f['t' - 'a']));
  cout << minn;
}
