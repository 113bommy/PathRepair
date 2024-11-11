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
    } else if (n > s) {
      cout << 0 << endl;
    } else {
      n = n / 2 + 1;
      cout << s / n << endl;
    }
  }
  return 0;
}
