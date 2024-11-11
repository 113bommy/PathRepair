#include <bits/stdc++.h>
using namespace std;
long long t = 1, n;
string s;
int main() {
  std::ios::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> t;
  while (t--) {
    cin >> n >> s;
    long long l1, r1, l2, r2;
    l1 = r1 = l2 = r2 = -1;
    long long l = 0, r = 0;
    for (int i = n / 2; i < n; i++) {
      if (s[i] == '0') {
        l1 = 1;
        r1 = i + 1;
        l2 = 1;
        r2 = i;
      }
    }
    for (int i = n / 2 + 1; i >= 0; i--) {
      if (s[i] == '0') {
        l1 = i + 1;
        r1 = n;
        l2 = i + 2;
        r2 = n;
      }
    }
    while (l <= r && r < n) {
      if (s[r] == '0') {
        l = r + 1;
        r = l;
      } else {
        if ((r - l + 1) > (n / 2)) {
          l1 = l + 1;
          r1 = r;
          l2 = l + 2;
          r2 = r + 1;
        }
        r++;
      }
    }
    cout << l1 << ' ' << r1 << ' ' << l2 << ' ' << r2 << "\n";
  }
  return 0;
}
