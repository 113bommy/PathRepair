#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      int ok = 0;
      for (int j = 0; j < n - 1; j++) {
        if (a[j] > a[j + 1]) {
          ok = 1;
        }
      }
      if (!ok) break;
      ++cnt;
      if (cnt % 2 == 0) {
        for (int j = 1; j < n - 1; j += 2) {
          if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
        }
      } else {
        for (int j = 0; j < n; j += 2) {
          if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
        }
      }
    }
    cout << cnt << endl;
  }
  return 0;
}
