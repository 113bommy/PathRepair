#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> h;
    vector<int> v(n + 1);
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      h.push_back(a);
    }
    for (int i = 1; i < n - 1; i++) {
      if (h[i] > h[i - 1] && h[i] > h[i + 1]) {
        v[i + 1] = 1;
      } else {
        v[i + 1] = 0;
      }
    }
    for (int i = 1; i <= n; i++) {
      v[i] = v[i] + v[i - 1];
    }
    int mx = 0, count = 0, mn = 1e9;
    for (int i = n; i >= k; i--) {
      mx = max(mx, v[i - 1] - v[i - k + 1]);
      if (v[i - 1] - v[i - k + 1] == mx) {
        mn = min(i - k + 1, mn);
      }
    }
    if (mx == 0) {
      cout << 1 << " " << 1 << "\n";
    } else
      cout << mx + 1 << " " << mn << "\n";
    ;
  }
}
