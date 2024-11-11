#include <bits/stdc++.h>
const int mx = 1e5 + 10;
using namespace std;
int a[mx], b[mx];
vector<int> v;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, k, ma = -1e9, mi = 1e9;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    ma = max(ma, a[i]);
    mi = min(mi, a[i]);
  }
  if (k == 1) {
    return cout << mi, 0;
  } else if (k == 2) {
    return cout << max(a[0], a[n - 1]), 0;
  } else {
    cout << mx << endl;
  }
}
