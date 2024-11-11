#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int knl = 1;
  for (int i = 2; i <= n; i++) {
    if (a[i] > a[knl]) knl = i;
  }
  if (a[knl] < 0) {
    cout << a[knl] << '\n';
    cout << n - 1 << '\n';
    for (int i = n; i > knl; i--) {
      cout << i << '\n';
    }
    for (int i = 1; i < knl; i++) {
      cout << i << '\n';
    }
    return 0;
  }
  long long sums[2] = {};
  vector<vector<int>> xs(2);
  for (int t = 0; t < 2; t++) {
    for (int i = 2 - t; i <= n; i += 2) {
      if (a[i] > 0) {
        sums[t] += a[i];
        xs[t].push_back(i);
      }
    }
  }
  int pty = sums[0] > sums[1] ? 0 : 1;
  cout << sums[pty] << '\n';
  vector<int> x = xs[pty];
  int s = x.size();
  vector<int> ret;
  for (int j = n; j > x[s - 1]; j--) {
    ret.push_back(j);
  }
  for (int i = s - 1; i >= 1; i--) {
    for (int j = (x[i - 1] + x[i]) / 2; j > x[i - 1]; j--) {
      ret.push_back(j);
    }
  }
  for (int j = 1; j < x[0]; j++) {
    ret.push_back(j);
  }
  cout << ret.size() << '\n';
  for (int crr : ret) {
    cout << crr << '\n';
  }
  return 0;
}
