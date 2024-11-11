#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  int n;
  cin >> n;
  int i, j, k;
  for (i = 0; i < n; i++) {
    int ans = 0;
    for (j = 0; j < n; j++) {
      cin >> k;
      if (i == j) continue;
      ans |= k;
    }
    cout << ans << " ";
  }
  return 0;
}
