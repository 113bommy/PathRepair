#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int main() {
  int l1, r1, t1, l2, r2, t2;
  cin >> l1 >> r1 >> t1 >> l2 >> r2 >> t2;
  if (l1 > l2) {
    swap(l1, l2);
    swap(r1, r2);
    swap(t1, t2);
  }
  int g = gcd(t1, t2);
  if ((l2 - l1) % g == 0) {
    cout << min(r1 - l1, r2 - l2) + 1 << endl;
  } else {
    int re = (l2 - l1) % g;
    int ans = max(0, min(r2 - l2 + 1, r1 - l1 + 1 - re));
    ans = max(ans, min(r1 - l1 + 1, r2 - l2 + 1 - (g - re)));
    cout << ans << endl;
  }
  return 0;
}
