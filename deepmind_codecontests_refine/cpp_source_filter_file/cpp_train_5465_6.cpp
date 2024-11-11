#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, s, q;
  cin >> t >> s >> q;
  long long c = 0;
  long long k = 0;
  long long ans = 0;
  long long f = 0;
  while (t--) {
    if (c == 0) {
      c++;
      f--;
      if (f == -1) {
        ans++;
        f = f + s;
      }
    } else {
      c++;
      s++;
    }
    if (c == q) {
      c = 0;
    }
  }
  cout << ans << endl;
}
