#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int k, l, d, ans = 0;
  cin >> k >> l;
  while (1) {
    d *= l;
    ans++;
    if (d == k) {
      cout << "YES" << endl;
      cout << ans;
      break;
    } else if (l > k) {
      cout << "NO";
      break;
    }
  }
  return 0;
}
