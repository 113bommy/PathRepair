#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, ans = 0, p, q;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p >> q;
    ans += q - p > 2 ? 1 : 0;
  }
  cout << ans << endl;
}
