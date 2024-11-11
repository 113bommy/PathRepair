#include <bits/stdc++.h>
using namespace std;
long long ans, l1, l2, r1, r2, k;
int main() {
  cin >> l1 >> r1 >> l2 >> r2 >> k;
  if (l2 < l1) {
    swap(l1, l2);
    swap(r1, r2);
  }
  if (l1 <= l2 && l2 <= r1) {
    if (r2 <= r1) {
      ans = r2 - l2 + 1;
      if (k >= l2 && k <= r2) ans--;
    }
    if (r2 > r1) {
      ans = r1 - l2 + 1;
      if (k >= l2 && k <= r1) ans--;
    }
  }
  cout << ans;
}
