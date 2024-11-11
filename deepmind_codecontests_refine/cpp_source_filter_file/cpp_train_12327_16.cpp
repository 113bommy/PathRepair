#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> g(n);
  for (int i = 0; i < n; i++) {
    cin >> g[i];
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 1; j < n; j++) {
      if (g[j - 1] > g[j]) {
        swap(g[j], g[j - 1]);
        ans++;
      }
    }
  }
  if (ans == 0 || ans == 1) cout << ans << endl;
  if (ans % 2) {
    cout << ans * 2 - 1 << endl;
  } else {
    cout << ans * 2 << endl;
  }
  return 0;
}
