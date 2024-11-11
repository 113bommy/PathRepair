#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int z = n / 3;
    int x = n % 3;
    int ans1 = z;
    int ans2 = z;
    if (x == 1) ans1++;
    if (x == 2) ans2++;
    cout << ans1 << " " << ans2;
  }
  return 0;
}
