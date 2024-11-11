#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = 0;
  cin >> n;
  vector<int> x(2 * n);
  int cnt = 0;
  int ans = 0;
  for (int i = 0; i < n * 2; i++) cin >> x[i];
  set<int> s;
  for (int i = 0; i < n * 2; i++) {
    if (s.empty() || !s.count(x[i])) {
      cnt++;
      s.insert(x[i]);
    } else {
      ans = max(ans, cnt);
      s.erase(x[i]);
      cnt--;
    }
  }
  ans = max(ans, cnt);
  cout << ans;
  return (0);
}
