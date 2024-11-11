#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-9;
const int inf = LONG_MAX;
struct pt {
  int x, y;
};
int n, tr, m, ans = 0;
string s, sl, sr;
void mod(int &a, int MOD) {
  if (a < 0)
    a += MOD;
  else
    a %= MOD;
}
bool isnum(string s) { return s[0] != '0'; }
bool cmp(string s1, string s2) {
  int l = s1.length(), r = s2.length();
  if (l == r)
    return s1 >= s2;
  else
    return l > r;
}
int main() {
  cin >> s;
  n = s.length();
  tr = n - 1;
  while (true) {
    m = tr - 1;
    sl = s.substr(0, m + 1);
    sr = s.substr(m + 1, tr - m);
    while ((!(isnum(sr) && cmp(sl, sr))) && m >= 0) {
      m--;
      sl = s.substr(0, m + 1);
      sr = s.substr(m + 1, tr - m);
    }
    ans++;
    if (m == -1) break;
    tr = m;
  }
  cout << ans;
}
