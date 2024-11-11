#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, a, b;
  cin >> n >> a >> b;
  if (abs(a - b) > 1 || (a + b) > n - 2) {
    cout << -1;
    return;
  }
  vector<int> v(n);
  for (int i = (0); i < (n); i++) v[i] = i + 1;
  if (a > b) {
    swap(v[n - 1], v[n - 2]);
    a--;
    for (int i = 1; i < n; i += 2) {
      if (a > 0) {
        swap(v[i], v[i + 1]);
        a--;
      } else
        break;
    }
  } else if (b > a) {
    swap(v[0], v[1]);
    for (int i = 2; i < n; i++) {
      if (a > 0) {
        swap(v[i], v[i + 1]);
        a--;
      } else
        break;
    }
  } else if (a == b) {
    for (int i = 1; i < n; i += 2) {
      if (a > 0) {
        swap(v[i], v[i + 1]);
        a--;
      } else
        break;
    }
  }
  for (auto x : v) cout << x << " ";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << endl;
  }
  return 0;
}
