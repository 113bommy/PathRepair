#include <bits/stdc++.h>
using namespace std;
bool gt(long double a, long double b) { return a > b + 1e-9; }
const int MAXN = 101 * 1000;
int match[MAXN];
string a, b;
int main() {
  ios::sync_with_stdio(false);
  memset(match, -1, sizeof match);
  cin >> a >> b;
  int max_diff = ((int)(a).size()) - 1, last = 0;
  for (register int i = (0); i < (int)(((int)(a).size())); ++i)
    if (a[i] == '4' || a[i] == '7') {
      if (last < ((int)(b).size()) && a[i] == b[last])
        last = match[i] = last + 1;
      else {
        max_diff = i;
        break;
      }
    } else
      match[i] = last;
  for (int diff = max_diff; diff >= 0; diff--)
    for (register int dig = (a[diff] + 1); dig < (int)('9' + 1); ++dig) {
      int till_now = diff ? match[diff] : 0;
      if (dig == '4' || dig == '7') {
        if (till_now == ((int)(b).size()) || b[till_now] != dig)
          continue;
        else
          till_now++;
      }
      int rem = ((int)(b).size()) - till_now;
      if (rem > ((int)(a).size()) - 1 - diff) continue;
      for (register int i = (0); i < (int)(diff); ++i) cout << a[i];
      cout << char(dig);
      for (register int i = (diff + 1); i < (int)(((int)(a).size()) - rem); ++i)
        cout << '0';
      for (register int i = (0); i < (int)(rem); ++i)
        cout << b[((int)(b).size()) - rem + i];
      cout << endl;
      return 0;
    }
  string x = b;
  if (((int)(x).size()) <= ((int)(a).size())) {
    int need = ((int)(a).size()) - ((int)(x).size()) + 1;
    x = "1" + string(need - 1, '0') + x;
  }
  cout << x << endl;
  return 0;
}
