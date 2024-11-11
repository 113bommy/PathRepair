#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, M = 27, mod = 998244353, OO = 0x3f3f3f3f, sqr = 320;
const long long LOO = 0x3f3f3f3f3f3f3f3f;
const long double eps = 1e-8;
set<string> st;
string xx, yy;
long long x, y;
bool flag;
void dp(string xx) {
  if (xx.size() > 60 || st.count(xx)) return;
  st.insert(xx);
  if (xx == yy) {
    flag = true;
    return;
  }
  string s, t;
  int i;
  for (i = 0; xx[i] != '1' && i < xx.size(); i++)
    ;
  s = xx.substr(i, xx.size() - i);
  std::reverse(s.begin(), s.end());
  dp(s);
  for (i = 0; xx[i] != '1' && i < xx.size(); i++)
    ;
  t = xx.substr(i, xx.size() - i);
  t = t + "1";
  std::reverse(t.begin(), t.end());
  dp(t);
}
void solve() {
  cin >> x >> y;
  while (x) {
    int k = x % 2;
    xx = xx + ((k == 1) ? "1" : "0");
    x /= 2;
  }
  std::reverse(xx.begin(), xx.end());
  while (y) {
    int k = y % 2;
    yy = yy + ((k == 1) ? "1" : "0");
    y /= 2;
  }
  std::reverse(yy.begin(), yy.end());
  dp(xx);
  (flag) ? cout << "YES" : cout << "NO";
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int tt = 1;
  while (tt--) solve();
  return 0;
}
