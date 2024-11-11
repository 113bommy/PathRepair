#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    long long mx = -0x3f3f3f3f3f3f3f3f, mn = 0x3f3f3f3f3f3f3f3f;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      mx = max(mx, a[i]);
      mn = min(mn, a[i]);
    }
    for (auto& x : a) cout << (k & 1 ? mx - x : x - mn) << " ";
    cout << "\n";
  }
  return 0;
}
