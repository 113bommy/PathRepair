#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int s, a, b, c, r, rem, t, cnt, x;
  cin >> t;
  while (t--) {
    r = 0;
    cin >> s >> a >> b >> c;
    r += s / c;
    x = s / a;
    cnt = x * b;
    cout << r + cnt;
    cout << "\n";
  }
}
