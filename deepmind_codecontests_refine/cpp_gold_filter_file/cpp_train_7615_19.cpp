#include <bits/stdc++.h>
using namespace std;
using llint = long long;
using pint = pair<int, int>;
const int INF = 1 << 28;
int t;
vector<llint> n;
vector<llint> k;
vector<llint> ans;
int main() {
  cin >> t;
  n.resize(t);
  k.resize(t);
  ans.resize(t);
  for (int i = 0; i < t; ++i) {
    cin >> n.at(i) >> k.at(i);
  }
  for (int i = 0; i < t; ++i) {
    llint cn = n.at(i);
    llint ck = k.at(i);
    while (cn != 0) {
      if (cn % ck == 0) {
        ++ans.at(i);
        cn /= ck;
      } else {
        ans.at(i) += cn - (cn / ck) * ck;
        cn = (cn / ck) * ck;
      }
    }
  }
  for (int i = 0; i < t; ++i) {
    cout << ans.at(i) << endl;
  }
  return 0;
}
