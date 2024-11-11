#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long q;
  cin >> q;
  while (q--) {
    long long l, r, d, c;
    cin >> l >> r >> d;
    if (l > d) {
      cout << d << " \n";
    } else {
      c = floor(r / d);
      c += 1;
      cout << c * d;
    }
  }
}
