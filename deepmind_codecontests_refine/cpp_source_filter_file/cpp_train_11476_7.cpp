#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (n <= m) {
    int ans = 1;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        ans = (ans * abs(a[j] - a[i])) % m;
      }
    }
    cout << ans << endl;
  } else {
    cout << 0 << endl;
  }
}
