#include <bits/stdc++.h>
using namespace std;
long long int temp;
vector<long long int> v;
long long int n;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t = 1;
  cin >> t;
  while (t--) {
    long long int n, strt, cnst, lwr = 0, upr = 0, t, l, r, pt = 0, flag = 0;
    cin >> n >> strt;
    lwr = strt, upr = strt;
    for (long long int i = 0; i < n; i++) {
      cin >> t >> l >> r;
      temp = t - pt;
      lwr = lwr - temp;
      upr = upr + temp;
      if (lwr <= l && upr >= r)
        lwr = l, upr = r;
      else if (lwr <= l && upr <= r && upr >= l)
        lwr = l;
      else if (lwr >= l && upr >= r && lwr <= r)
        upr = r;
      else if (lwr > l && upr < r)
        lwr = lwr, upr = upr;
      else
        flag = 1;
      pt = t;
    }
    if (flag == 1)
      cout << "NO";
    else
      cout << "YES";
    cout << "\n";
  }
}
