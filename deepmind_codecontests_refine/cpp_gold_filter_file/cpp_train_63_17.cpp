#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int ans = 101;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    if (k % a == 0) {
      ans = min(ans, k / a);
    }
  }
  cout << ans << "\n";
}
