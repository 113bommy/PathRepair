#include <bits/stdc++.h>
using namespace std;
int main() {
  int p, q, n, i, s = 0;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> p >> q;
    if ((q - p) > 2) {
      s = s + 1;
    }
  }
  cout << s;
}
