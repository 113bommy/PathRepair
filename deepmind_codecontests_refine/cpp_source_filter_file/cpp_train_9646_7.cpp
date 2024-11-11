#include <bits/stdc++.h>
using namespace std;
int main() {
  int v;
  cin >> v;
  string s = to_string(v);
  int mx = pow(2, s.size()), pos = 1, ans = 0x3f3f3f3f;
  while (pos < mx) {
    string temp;
    int tp = pos, i = 0;
    while (tp) {
      if (tp % 2) {
        if (temp.size())
          temp += s[i];
        else if (s[i] > '0')
          temp += s[i];
      }
      tp /= 2, ++i;
    }
    int nw = atoi(temp.c_str());
    if (int(sqrt(nw)) * int(sqrt(nw)) == nw || nw * nw == nw)
      ans = min(ans, int(s.size() - temp.size()));
    pos++;
  }
  if (ans == 0x3f3f3f3f)
    cout << -1;
  else
    cout << ans;
}
