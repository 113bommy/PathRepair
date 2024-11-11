#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    long long k, x, ans;
    cin >> k >> x;
    ans = x + (k - 1) * 9;
    cout << ans << endl;
  }
  return 0;
}
