#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int t, n, ans;
vector<int> a, v;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    ans = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      a.push_back(x);
      v.push_back(x);
    }
    sort(v.begin(), v.end());
    while (1) {
      if (a == v) break;
      ans++;
      for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
          if (ans & 1 && i & 1) {
            swap(a[i], a[i + 1]);
          } else if (!(ans & 1) && !(i & 1)) {
            swap(a[i], a[i + 1]);
          }
        }
      }
    }
    cout << ans << endl;
    a.clear();
    v.clear();
  }
  return 0;
}
