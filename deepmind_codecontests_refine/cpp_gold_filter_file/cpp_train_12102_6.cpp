#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n, 0);
    set<int> s;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      s.insert(a[i]);
    }
    if (s.size() > k) {
      cout << -1 << '\n';
      continue;
    }
    cout << n * k << '\n';
    for (int i = 0; i < n; i++) {
      for (auto it : s) {
        cout << it << " ";
      }
      for (int j = int(1); j < int(k - s.size() + 1); ++j) {
        cout << j << " ";
      }
    }
    cout << '\n';
  }
}
