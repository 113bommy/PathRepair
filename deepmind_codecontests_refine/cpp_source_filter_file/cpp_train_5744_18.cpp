#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool check(int m) {
  int sum = 0;
  while (m) {
    sum += m % 10;
    m = m / 10;
  }
  if (sum % 4 == 0)
    return true;
  else
    return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t = 1;
  while (t--) {
    int n;
    cin >> n;
    int m = n;
    int sum = 0;
    while (m) {
      sum += m % 10;
      m = m / 10;
    }
    if (sum % 4 == 0)
      cout << n;
    else {
      int ans;
      for (int i = n + 1; i <= 2 * n; i++) {
        if (check(i) == true) {
          ans = i;
          break;
        }
      }
      cout << ans;
    }
    cout << "\n";
  }
}
