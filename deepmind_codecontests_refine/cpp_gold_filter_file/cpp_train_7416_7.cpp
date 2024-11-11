#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int cnt = 0;
    while (n > 1) {
      int i = 1;
      int need = 2;
      int pd = 2;
      while (need <= n) {
        pd = need;
        i++;
        need += 3 * i - 1;
      }
      n -= pd;
      cnt++;
    }
    cout << cnt << "\n";
  }
  return 0;
}
