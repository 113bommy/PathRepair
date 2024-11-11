#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long k;
  cin >> k;
  if (k > 36)
    cout << -1;
  else {
    if (k == 1)
      cout << 4;
    else if (k == 2)
      cout << 8;
    else {
      long long s = 0;
      while (k > 0) {
        s = s * 10 + 8;
        k -= 2;
      }
      if (k < 0) {
        s /= 10;
        s = s * 10 + 4;
      }
      cout << s;
    }
  }
}
