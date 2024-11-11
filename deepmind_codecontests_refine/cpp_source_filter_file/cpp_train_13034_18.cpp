#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<int> v(n);
    long long s = 0, x = 0;
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      s += v[i];
      x ^= v[i];
    }
    vector<long long> ans;
    if (s % 2)
      ans.push_back((1ll << 60) + 1);
    else
      ans.push_back(1ll << 60);
    s += ans[0];
    x ^= ans[0];
    ans.push_back((2 * x - s) / 2);
    ans.push_back(ans[1]);
    cout << ans.size() << '\n'
         << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
  }
}
