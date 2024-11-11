#include <bits/stdc++.h>
const int MOD = 1000000007;
using namespace std;
int main() {
  int n;
  cin >> n;
  map<int, int> mp;
  if (n == 1) {
    int x;
    cin >> x;
    cout << 1 << endl;
    return 0;
  }
  set<int> s;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    s.insert(x);
    for (int j = 2; j * j <= x; j++) {
      if (x % j == 0) {
        int count = 0;
        while (x % j == 0) {
          count++;
          x /= j;
        }
        mp[j] += 1;
      }
    }
    if (x > 1) {
      mp[x]++;
    }
  }
  int ans = 0;
  if (s.size() == 1 and *s.begin() == 1) {
    cout << 1 << endl;
    return 0;
  }
  for (auto x : mp) {
    ans = max(ans, x.second);
  }
  cout << ans << endl;
}
