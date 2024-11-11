#include <bits/stdc++.h>
using namespace std;
mt19937 rng(time(0));
uniform_int_distribution<int> uid(-1e9, 1e9);
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, ok = 1, x = 0;
  string s;
  cin >> n >> s;
  for (int i = 1; i < n; ++i) ok &= !(s[i] == '1' && s[i - 1] == '1');
  for (int i = 2; i < n; ++i)
    x |= (s[i] == '0' && s[i - 1] == '0' && s[i - 2] == '0');
  x |= s.size() > 2 && ((s[0] == '0' && s[1] == '0') ||
                        (s[s.size() - 1] == '0' && s[s.size() - 2] == '0'));
  cout << (char*)&(const int&)(23438671621410638LL >>
                               ((ok && !x && (n != 1 || s == "1")) << 5));
}
