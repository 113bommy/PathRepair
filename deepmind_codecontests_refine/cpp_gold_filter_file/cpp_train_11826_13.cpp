#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<long long> a(n);
  for (long long &x : a) {
    cin >> x;
  }
  int res = INT_MAX;
  int ans = 1;
  sort(a.begin(), a.end());
  for (int i = 1; i < n; i++) {
    int d = a[i] - a[i - 1];
    if (d == res) {
      ans++;
    } else if (d < res) {
      res = d;
      ans = 1;
    }
  }
  cout << res << " " << ans;
}
