#include <bits/stdc++.h>
using namespace std;
int a[1000000];
vector<int> ll;
multiset<int> rr;
signed main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n / 2; ++i) {
    ll.push_back(a[i]);
  }
  for (int i = n; i >= (n + 1) / 2 + 1; --i) {
    rr.insert(a[i]);
  }
  int ans = 0;
  for (int i = 0; i < ll.size(); ++i) {
    auto it = rr.lower_bound(ll[i] * 2);
    if (it == rr.end()) {
      break;
    }
    ++ans;
    rr.erase(it);
  }
  cout << n - ans << endl;
}
