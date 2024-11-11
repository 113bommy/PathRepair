#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int p0, p1;
  cin >> p0 >> p1;
  n -= 2;
  if (n == 0) {
    cout << "2\n" << p0 << ' ' << p1 << '\n';
    return;
  }
  vector<int> res;
  res.push_back(p0);
  while (n) {
    int p2;
    cin >> p2;
    --n;
    if (res.back() < p1 != p1 < p2) {
      res.push_back(p1);
    }
    p1 = p2;
  }
  res.push_back(p1);
  cout << res.size() << '\n';
  for (auto r : res) cout << r << ' ';
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  for (int i = 0; i != t; ++i) {
    solve();
  }
  return 0;
}
