#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int main() {
  ios_base::sync_with_stdio(false);
  int n, cnt = 0, ans = -INF;
  cin >> n;
  set<int> aa;
  for (int i = 0; (i) < (n); ++i) {
    int val;
    cin >> val;
    if (aa.count(val) == 1) {
      aa.erase(val);
      cnt--;
    } else {
      cnt++;
      aa.insert(val);
      ans = max(ans, cnt);
    }
  }
  cout << ans;
  return 0;
}
