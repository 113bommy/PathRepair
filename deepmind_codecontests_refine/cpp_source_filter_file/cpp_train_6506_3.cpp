#include <bits/stdc++.h>
using namespace std;
long long n, m, ans;
string st;
int main() {
  cin >> n >> m;
  cin >> st;
  ans = n * m - n;
  for (int k = 0; k < st.size(); ++k) {
    if (k > 0 && st[k] != st[k - 1]) ans += n * m - n;
  }
  int c = 1;
  for (int k = 1; k < st.size(); ++k) {
    if (c == 1) {
      if (st[k] == st[k - 1]) continue;
      if (st[k] != st[k - 1]) {
        ++c;
      }
      continue;
    }
    if (st[k] == st[k - 2])
      ++c;
    else {
      ans -= (c * (c - 1)) / 2;
      if (st[k] != st[k - 1])
        c = 2;
      else
        c = 1;
    }
  }
  ans -= (c * (c - 1)) / 2;
  cout << ans;
  return 0;
}
