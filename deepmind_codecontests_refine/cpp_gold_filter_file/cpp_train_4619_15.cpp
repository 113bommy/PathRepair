#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, ans = 0;
  cin >> n;
  while (n--) {
    int sum = 0, t;
    for (int i = 0; i < 3; i++) {
      cin >> t;
      sum += t;
    }
    if (sum > 1) ans++;
  }
  cout << ans << endl;
  return 0;
}
