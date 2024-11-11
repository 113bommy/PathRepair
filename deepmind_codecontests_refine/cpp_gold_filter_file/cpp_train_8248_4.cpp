#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a, a + n);
    int b[n];
    bool b0 = true;
    for (int i = 1; i < 1024; i++) {
      for (int j = 0; j < n; j++) {
        b[j] = a[j] ^ i;
      }
      sort(b, b + n);
      bool bo = true;
      for (int j = 0; j < n; j++) {
        if (a[j] != b[j]) {
          bo = false;
          break;
        }
      }
      if (bo) {
        b0 = false;
        cout << i << "\n";
        break;
      }
    }
    if (b0) cout << "-1\n";
  }
}
