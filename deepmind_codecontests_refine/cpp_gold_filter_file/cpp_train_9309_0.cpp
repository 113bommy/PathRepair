#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, n, l, r, parts;
  cin >> t;
  while (t--) {
    cin >> n >> l >> r;
    if (n % l == 0 || n % r == 0) {
      cout << "Yes\n";
      continue;
    } else {
      parts = n / l;
      if (r * parts > n) {
        cout << "Yes\n";
        continue;
      }
    }
    cout << "No\n";
  }
  return 0;
}
