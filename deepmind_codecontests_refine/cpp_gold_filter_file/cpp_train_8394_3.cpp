#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int INF = 1000000000;
int n, l, r;
set<pair<int, int> > cur;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> l >> r;
    auto it = cur.lower_bound({-r, -1});
    int curL = -l;
    int curR = r;
    while ((it != cur.end()) && (-it->second <= curL)) {
      curL = max(curL, it->first);
      curR = max(curR, it->second);
      cur.erase(it);
      it = cur.lower_bound({-curR, 0});
    }
    cur.insert({curL, curR});
    cout << cur.size() << "\n";
  }
  cout << "\n"
       << "\n";
  return 0;
}
