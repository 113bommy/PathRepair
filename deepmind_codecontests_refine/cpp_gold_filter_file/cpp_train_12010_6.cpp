#include <bits/stdc++.h>
using namespace std;
int main() {
  set<int> s;
  int n, a, x;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    s.insert(a);
  }
  if (s.size() == 1) {
    cout << "NO" << endl;
    return 0;
  }
  int count = 0, ans;
  for (auto u : s) {
    if (count == 2) break;
    ans = u;
    count++;
  }
  cout << ans << endl;
  return 0;
}
