#include <bits/stdc++.h>
using namespace std;
int n, x, y;
string s;
int p;
int main() {
  cin >> n >> x >> y >> s;
  s = '1' + s;
  for (int i = 1; i < s.size(); i++)
    if (s[i] == '0' && s[i - 1] == '1') p++;
  if (p == 0)
    cout << 0;
  else
    cout << 1LL * (p - 1) * min(x, y) + y;
  return 0;
}
