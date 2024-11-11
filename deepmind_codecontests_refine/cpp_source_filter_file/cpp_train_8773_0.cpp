#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &ai : a) {
      cin >> ai;
    }
    bool good = true;
    for (int i = 0, x = 1e7, y = 0; i < n; i++) {
      if (a[i] < y) {
        good = false;
        break;
      }
      x = min(x, y - a[i]);
      a[i] -= x;
      y = max(y, a[i]);
    }
    cout << (good ? "YES\n" : "NO\n");
  }
}
