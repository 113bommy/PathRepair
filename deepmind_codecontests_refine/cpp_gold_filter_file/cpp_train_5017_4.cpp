#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
int n;
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  set<int> m;
  vector<int> i(n);
  for (auto &x : i) cin >> x;
  vector<int> o(n);
  for (auto &x : o) cin >> x;
  int idx = 0;
  int ans = 0;
  for (int odx = 0; odx < n; odx++) {
    if (m.find(i[idx]) != m.end()) {
      idx++;
      odx--;
    } else if (i[idx] == o[odx])
      idx++;
    else {
      ans++;
      m.insert(o[odx]);
    }
  }
  cout << ans << "\n";
}
