#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int t[n];
  int ans[n];
  for (int i = 1; i <= n; i++) {
    cin >> t[i];
    ans[i] = 0;
  }
  for (int j = 1; j <= n; j++) {
    for (int i = 1; i <= n; i++) {
      if (j == t[i]) ans[j] = i;
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
  return 0;
}
