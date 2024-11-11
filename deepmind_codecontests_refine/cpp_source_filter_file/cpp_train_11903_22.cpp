#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double eps = 1e-11;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const double pi = acos(-1.0);
const int MAX_INT = (1 << 30);
const ll MAX_LL = (1LL << 62);
class NumericalPerfectionLevel {
 private:
 public:
};
int main() {
  int k;
  string s;
  cin >> k >> s;
  ll res = 0;
  if (k == 0) {
    int cnt = 0;
    for (int i = 0; i < (int)s.size(); i++) {
      if (s[i] == '0')
        cnt++;
      else {
        res += (ll)(cnt * (cnt + 1)) / 2;
        cnt = 0;
      }
    }
    res += (ll)((ll)cnt * (cnt + 1)) / 2;
    cout << res << '\n';
    return 0;
  }
  vector<int> all;
  all.push_back(-1);
  for (int i = 0; i < (int)s.size(); i++) {
    if (s[i] == '1') all.push_back(i);
  }
  all.push_back((int)s.size());
  int p1 = 1, p2 = k;
  while (p2 < (int)all.size() - 1) {
    res += (ll)(all[p1] - all[p1 - 1]) * (ll)(all[p2 + 1] - all[p2]);
    p1++, p2++;
  }
  cout << res << '\n';
  return 0;
}
