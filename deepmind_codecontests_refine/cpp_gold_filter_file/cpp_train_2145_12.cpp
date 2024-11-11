#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, a[1000], b[1000];
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < k; i++) cin >> b[i];
  if (k == 1) {
    for (int i = 0; i < n; i++) {
      if (a[i] == 0) {
        a[i] = b[0];
      }
    }
    for (int i = 0; i < n - 1; i++) {
      if (a[i] > a[i + 1]) {
        cout << "Yes";
        return 0;
      }
    }
    cout << "No";
  }
  if (k != 1) cout << "Yes";
  return 0;
}
