#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, i, k = 0;
    cin >> n;
    int a[n];
    map<int, int> m;
    set<int> s;
    for (i = 0; i < n; i++) {
      cin >> a[i];
      m[a[i]]++;
      k = max(k, m[a[i]]);
    }
    for (i = 0; i < n; i++) s.insert(a[i]);
    int mx = s.size();
    int ans = max(min(mx - 1, k), min(mx, k - 1));
    cout << ans;
  }
}
