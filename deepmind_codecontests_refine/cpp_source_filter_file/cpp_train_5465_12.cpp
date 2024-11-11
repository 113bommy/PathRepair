#include <bits/stdc++.h>
using namespace std;
int q, t, l, ans = 1, s1;
double s, d;
int main() {
  cin >> t >> s >> q;
  d = s;
  while (t > d) {
    l++;
    s1++;
    if (s1 == q) {
      d = s + q - 1;
      s = d;
      s1 = 0;
    } else
      d = s + s1 * double((q - 1)) / double(q);
    if (l > d) {
      l = 0;
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
