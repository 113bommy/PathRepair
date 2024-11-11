#include <bits/stdc++.h>
using namespace std;
string s, t;
long long nt, ns, uc, rg[200005], rpos, ans;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> s;
  cin >> t;
  nt = (long long)t.size();
  ns = (long long)s.size();
  uc = nt - 1;
  for (int i = ns - 1; i >= 0; i--) {
    if (uc >= 0) {
      if (s[i] == t[uc]) {
        rg[uc] = i;
        uc--;
      }
    }
  }
  uc = 0;
  for (int i = 0; i < ns; i++) {
    rpos = ns - 1;
    if (uc < nt) rpos = rg[uc] - 1;
    ans = max(ans, rpos - i + 1);
    if (uc < nt && t[uc] == s[i]) uc++;
  }
  cout << ans;
  return 0;
}
