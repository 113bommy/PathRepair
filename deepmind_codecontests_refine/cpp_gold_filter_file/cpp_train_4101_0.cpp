#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, k;
  cin >> n >> k;
  vector<unsigned int> ips;
  char _;
  for (int i = 0; i < n; i++) {
    unsigned int ip = 0;
    vector<int> ip_a(4);
    cin >> ip_a[3] >> _ >> ip_a[2] >> _ >> ip_a[1] >> _ >> ip_a[0];
    for (int j = 0; j < 4; j++)
      for (int b = 0; b < 8; b++)
        if (ip_a[j] & (1 << b)) {
          ip |= 1 << (8 * j + b);
        }
    ips.push_back(ip);
  }
  unsigned int mask = 0;
  for (int i = 31; i; i--) {
    mask |= 1 << i;
    set<unsigned int> nets;
    for (unsigned int ip : ips) {
      unsigned int net = mask & ip;
      nets.insert(net);
    }
    vector<int> ans;
    if (int(nets.size()) == k) {
      for (int j = 0; j < 4; j++) {
        ans.push_back(mask % (1 << 8));
        mask /= (1 << 8);
      }
      cout << ans[3] << '.' << ans[2] << '.';
      cout << ans[1] << '.' << ans[0] << '\n';
      return;
    }
  }
  cout << "-1\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
};
