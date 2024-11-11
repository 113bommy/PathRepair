#include <bits/stdc++.h>
using namespace std;
const double pi = atan2(0, -1);
set<int> apps[300001];
vector<int> q;
void solve() {
  vector<char> readQ;
  int n, m;
  cin >> n >> m;
  long long ans = 0;
  int read = 0;
  for (int i = 0; i < m; i++) {
    int t, x;
    cin >> t >> x;
    if (t == 1) {
      q.push_back(x);
      readQ.push_back(1);
      apps[x].insert(q.size() - 1);
      ans++;
    } else if (t == 2) {
      ans -= apps[x].size();
      for (auto c : apps[x]) readQ[c] = 0;
      apps[x] = {};
    } else {
      for (int i = read; i < x; i++) {
        if (readQ[i]) {
          ans--;
          apps[q[i]].erase(i);
        }
      }
      read = max(read, x);
    }
    cout << ans << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  while (t--) solve();
  return 0;
}
