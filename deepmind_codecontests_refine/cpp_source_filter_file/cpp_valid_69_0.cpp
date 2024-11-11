#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  long long a[66];
  a[0] = 1;
  vector<string> powers;
  powers.push_back(to_string(a[0]));
  for (int i = 1; i <= 64; i++) {
    a[i] = a[i - 1] * 2;
    string str = to_string(a[i]);
    powers.push_back(str);
  }
  while (t--) {
    string nss;
    cin >> nss;
    long long ans = nss.size() + 1;
    for (int i = 0; i < powers.size(); i++) {
      long long taken = 0;
      long long px = 0, pn = 0;
      while (px < powers[i].size() && pn < nss.size()) {
        if (powers[i][px] == nss[pn]) {
          taken++;
          px++;
        }
        pn++;
      }
      long long tt = nss.size() + powers[i].size() - 2 * taken;
      ans = min(ans, tt);
    }
    cout << ans << endl;
  }
}
