#include <bits/stdc++.h>
using namespace std;
int F(const vector<int>& vc, int bit) {
  if (vc.size() <= 3 || bit < 0) {
    return 0;
  }
  vector<int> vc1, vc2;
  for (int x : vc) {
    if (x >> bit == 0) {
      vc1.push_back(x);
    } else {
      vc2.push_back(x);
    }
  }
  return min(F(vc1, bit - 1) + max((int)(vc2.size() - 1), 0),
             F(vc2, bit - 1) + max((int)(vc1.size() - 1), 0));
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<int> vc;
  int n, x;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> x;
    vc.push_back(x);
  }
  int ans = F(vc, 29);
  cout << ans << endl;
  return 0;
}
