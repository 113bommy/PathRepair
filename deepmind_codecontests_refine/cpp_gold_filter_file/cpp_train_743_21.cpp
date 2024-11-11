#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, k, t, l, r, a, b, pos;
  cin >> n >> k >> m >> t;
  l = 1;
  r = n;
  pos = k;
  for (long long i = 0; i < t; i++) {
    cin >> a >> b;
    if (a == 0) {
      if (b < pos) {
        l += b;
        pos = pos - b;
        cout << r - l + 1 << " " << pos << endl;
      } else {
        b = r - l - b + 1;
        r -= b;
        cout << r - l + 1 << " " << pos << endl;
      }
    } else {
      if (b <= pos) {
        l--;
        pos++;
        cout << r - l + 1 << " " << pos << endl;
      } else {
        r++;
        cout << r - l + 1 << " " << pos << endl;
      }
    }
  }
}
