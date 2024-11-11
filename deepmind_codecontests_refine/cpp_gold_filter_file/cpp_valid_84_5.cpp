#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, s;
    cin >> n >> s;
    if (n == 1) {
      cout << s << endl;
    } else if (s == 1) {
      cout << 0 << endl;
    } else {
      int x = n / 2 + 1;
      cout << s / x << endl;
    }
  }
  return 0;
}
