#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  long long k, last = 0;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    cin >> k;
    if (k > last)
      ans += (k - last) * (n - k + 1);
    else if (k < last)
      ans += (last - k) * k;
    last = k;
  }
  cout << ans << endl;
  return 0;
}
