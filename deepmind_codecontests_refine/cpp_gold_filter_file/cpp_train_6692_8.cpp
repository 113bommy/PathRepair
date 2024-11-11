#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int digit = n % 10;
    string s = to_string(n);
    int digits = s.length();
    int ans = (digit - 1) * 10;
    if (digits == 1)
      cout << ans + 1 << endl;
    else if (digits == 2)
      cout << ans + 3 << endl;
    else if (digits == 3)
      cout << ans + 6 << endl;
    else
      cout << ans + 10 << endl;
  }
}
