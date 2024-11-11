#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    unordered_set<long long int> s;
    long long int mx = 0;
    for (long long int i = 0; i < n; i++) {
      long long int temp;
      cin >> temp;
      mx = max(mx, temp);
      s.insert(temp);
    }
    long long int ans = -1;
    for (long long int i = 1; i < mx + 1; i++) {
      long long int f = 1;
      for (auto it = s.begin(); it != s.end(); it++) {
        long long int x = (*it) ^ i;
        auto itx = s.find(x);
        if (itx == s.end()) {
          f = 0;
          break;
        }
      }
      if (f) {
        ans = i;
        break;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
