#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long down = 1e9, up = -1;
    bool ok = true;
    while (n--) {
      long long a;
      cin >> a;
      if (a - up < 0) ok = false;
      down = min(down, a - up);
      up = a - down;
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}
