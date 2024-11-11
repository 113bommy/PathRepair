#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    int a, b, c, r = 0;
    cin >> a >> b >> c;
    if (a) r++, a--;
    if (b) r++, b--;
    if (c) r++, c--;
    if (a >= c && a >= b) {
      if (a && b) r++, a--, b--;
      if (a && c) r++, a--, c--;
      if (b && c) r++, b--, c--;
    } else if (b >= a && b >= c) {
      if (b && a) r++, a--, b--;
      if (b && c) r++, c--, b--;
      if (a && c) r++, a--, c--;
    } else {
      if (c && b) r++, c--, b--;
      if (c && a) r++, c--, a--;
      if (a && b) r++, a--, b--;
    }
    if (a && b && c) r++;
    cout << r << "\n";
  }
}
