#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int ans = 0, spent;
    while (n >= 10) {
      spent = (n / 10) * 10;
      ans += spent;
      n = n - spent + spent / 10;
    }
    ans += n;
    cout << ans << endl;
  }
  return 0;
}
