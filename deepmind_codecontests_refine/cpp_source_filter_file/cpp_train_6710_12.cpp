#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int ans = 0;
  char x;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    if (x == '1') {
      ans++;
    } else
      break;
  }
  cout << ans + 1;
  return 0;
}
