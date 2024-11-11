#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int m, n, k, i, j, ans;
    cin >> n;
    if (n == 1 || n == 2)
      cout << "1";
    else if (n == 3)
      cout << "2";
    else {
      ans = n / 2;
      cout << ans;
    }
    cout << endl;
  }
  return 0;
}
