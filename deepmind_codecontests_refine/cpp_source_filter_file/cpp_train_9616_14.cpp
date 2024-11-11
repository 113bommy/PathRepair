#include <bits/stdc++.h>
using namespace std;
const long long m = 1e9 + 7;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  int x, y;
  for (int i = 0; i < n; i++) {
    if (a[i] % 2)
      x++;
    else
      y++;
  }
  if (x == 1) {
    for (int i = 0; i < n; i++) {
      if (a[i] % 2) {
        cout << i + 1;
        break;
      }
    }
  } else {
    for (int i = 0; i < n; i++) {
      if (a[i] % 2 == 0) {
        cout << i + 1;
        break;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
