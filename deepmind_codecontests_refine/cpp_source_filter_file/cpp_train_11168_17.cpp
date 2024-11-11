#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int i;
  i = 6;
  int ans[n + 1];
  int prev = -1;
  int tot = 0;
  while (i >= 2) {
    cout << "? " << 1 << " " << i << endl;
    int x;
    cin >> x;
    if (prev != -1) {
      ans[i + 1] = prev - x;
    } else {
      tot = x;
    }
    prev = x;
    i--;
  }
  cout << "? " << 2 << " " << n << endl;
  int x;
  cin >> x;
  ans[1] = tot - x;
  ans[2] = prev - ans[1];
  cout << "! ";
  for (i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}
