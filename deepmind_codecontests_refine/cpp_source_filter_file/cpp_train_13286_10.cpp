#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  ;
  cin.tie(0);
  ;
  long long int n, k, ans = 0;
  cin >> n >> k;
  if (k == 1) {
    cout << "1";
    return 0;
  }
  if (k == 2) {
    ans = 1 + (n * (n - 1)) / 2;
    cout << ans;
    return 0;
  }
  if (k == 3) {
    ans = 1 + (n * (n - 1)) / 2 + (n * (n - 1) * (n - 2)) / 3;
    cout << ans;
    return 0;
  }
  ans = 1 + (n * (n - 1)) / 2 + (n * (n - 1) * (n - 2)) / 3 +
        (n * (n - 1) * (n - 2) * (n - 3)) / 24;
  cout << ans;
  return 0;
}
