#include <bits/stdc++.h>
using namespace std;
int main() {
  ;
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n % 3 == 0) {
      cout << n / 3 << " 0 0\n";
    } else if (n % 3 == 1) {
      n -= 7;
      if (n < 0)
        cout << "-1\n";
      else
        cout << n / 3 << " 0 1\n";
    } else {
      n -= 5;
      if (n < 0)
        cout << "-1\n";
      else
        cout << n / 3 << " 1 0\n";
    }
  }
  return 0;
}
