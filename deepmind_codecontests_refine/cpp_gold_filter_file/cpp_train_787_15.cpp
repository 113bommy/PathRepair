#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int n, p1l, p1r, p2l, p2r;
string s, t, ans;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> s >> t;
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());
  ans.resize(s.length(), 0);
  p1l = 0;
  p2r = (int)s.length() - 1;
  p1r = ((int)s.length() + 1) / 2 - 1;
  p2l = p2r - (int)s.length() / 2 + 1;
  n = (int)s.length() - 1;
  for (int i = 0, nm = 0; i <= n; ++i, ++nm) {
    if (t[p2r] <= s[p1l]) {
      if (nm % 2 == 0)
        ans[n] = s[p1r--];
      else
        ans[n] = t[p2l++];
      n -= 1;
      i -= 1;
    } else {
      if (nm % 2 == 0)
        ans[i] = s[p1l++];
      else
        ans[i] = t[p2r--];
    }
  }
  cout << ans;
  return 0;
}
