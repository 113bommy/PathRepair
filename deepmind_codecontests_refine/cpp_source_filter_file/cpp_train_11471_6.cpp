#include <bits/stdc++.h>
using namespace std;
int main() {
  int q, n;
  vector<int> a(10010);
  cin >> q;
  while (q--) {
    cin >> n;
    for (int i = 0; i < 10010; i++) a[i] = 0;
    for (int i = 0; i < 4 * n; i++) {
      int v;
      cin >> v;
      a[v]++;
    }
    bool ok = true;
    for (int i = 0; i < 1010; i++) {
      if (a[i] % 2 != 0) ok = false;
      a[i] /= 2;
    }
    if (ok == false) {
      cout << "NO" << endl;
      continue;
    }
    int l = 0, r = 10000, area = 0;
    while (l <= r) {
      while (l <= r && a[l] <= 0) l++;
      while (l <= r && a[r] <= 0) r--;
      if (l > r) break;
      a[l]--;
      a[r]--;
      int t = l * r;
      if (area == 0 || t == area)
        area = t;
      else {
        ok = false;
        break;
      }
    }
    cout << (ok ? "YES" : "NO") << endl;
  }
  return 0;
}
