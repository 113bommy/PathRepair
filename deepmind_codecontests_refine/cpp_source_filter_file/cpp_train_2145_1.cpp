#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[105], b[105];
bool pos = false;
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= k; i++) cin >> b[i];
  if (k > 1) {
    cout << "Yes\n";
  } else {
    for (int i = 0; i < n; i++) {
      if (a[i] == 0) {
        a[i] = b[1];
      }
    }
    for (int i = 1; i < n; i++) {
      if (a[i] >= a[i + 1]) {
        pos = true;
        break;
      }
    }
    cout << (pos ? "Yes\n" : "No\n");
  }
}
