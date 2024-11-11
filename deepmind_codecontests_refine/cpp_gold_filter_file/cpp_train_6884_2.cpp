#include <bits/stdc++.h>
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int NINF = -INF - 1;
const int maxn = 5e5 + 10;
using namespace std;
int main() {
  string ss;
  cin >> ss;
  int len = ss.length();
  int l = 0, r = len - 1;
  int t = 0;
  for (int i = 0; i < len; ++i) {
    if (ss[i] == '[') {
      t++;
      l = i;
      break;
    }
  }
  for (int i = len - 1; i >= 0; --i) {
    if (ss[i] == ']') {
      t++;
      r = i;
      break;
    }
  }
  int st = l, ed = r;
  for (int i = l; i <= r; ++i) {
    if (ss[i] == ':') {
      t++;
      st = i;
      break;
    }
  }
  for (int i = r; i >= l; --i) {
    if (ss[i] == ':' && i != st) {
      t++;
      ed = i;
      break;
    }
  }
  if (t != 4) {
    cout << "-1";
    return 0;
  }
  int ans = 4;
  for (int i = st; i < ed; ++i) {
    if (ss[i] == '|') ans++;
  }
  cout << ans;
  return 0;
}
