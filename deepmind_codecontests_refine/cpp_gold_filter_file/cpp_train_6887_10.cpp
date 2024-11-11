#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int k, l, d = 1, ans = -1;
  cin >> l >> k;
  while (1) {
    d *= l;
    ans++;
    if (d == k) {
      cout << "YES" << endl;
      cout << ans;
      break;
    } else if (d > k) {
      cout << "NO";
      break;
    }
  }
  return 0;
}
