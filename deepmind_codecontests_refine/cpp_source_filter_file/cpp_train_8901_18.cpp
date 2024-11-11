#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(0);
  vector<int> ar = {6, 2, 5, 5, 4, 5, 6, 3, 7, 8};
  int a, b;
  cin >> a >> b;
  long long ans = 0;
  for (int i = a; i <= b; ++i) {
    int z = i;
    while (z) {
      ans += (long long)ar[z % 10];
      z /= 10;
    }
  }
  cout << ans << '\n';
}
