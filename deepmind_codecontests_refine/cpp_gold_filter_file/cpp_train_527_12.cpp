#include <bits/stdc++.h>
using namespace std;
int a[500005];
int main() {
  int n, i, j, k, l, res;
  string ss;
  string tt;
  cin >> n >> k;
  cin >> ss;
  sort(ss.begin(), ss.end());
  char pp = ss[0];
  tt.push_back(pp);
  for (i = 1; i < ss.size(); i++) {
    char qq = ss[i];
    if (ss[i] - pp >= 2) {
      tt.push_back(ss[i]);
      pp = ss[i];
    }
  }
  if (tt.size() < k) {
    cout << -1 << '\n';
  } else {
    res = 0;
    for (i = 0; i < k; i++) {
      res = res + tt[i] - 'a' + 1;
    }
    cout << res << '\n';
  }
  return 0;
}
