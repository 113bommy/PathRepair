#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, q, u, i, l;
  string s;
  cin >> n >> q;
  i = 1;
  while (n /= 2) i++;
  n = i;
  while (q--) {
    cin >> u >> s;
    l = 1;
    while ((u & 1) == 0) l++, u /= 2;
    i = (u - 1) / 2;
    for (char c : s) {
      if (c == 'U') {
        if (l < n) l++, i /= 2;
      } else {
        if (l > 1) l--, i *= 2, i += (c == 'R');
      }
    }
    u = (1ll << (l - 1)) + i * (1ll << l);
    cout << u << " ";
  }
}
