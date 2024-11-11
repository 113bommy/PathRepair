#include <bits/stdc++.h>
using namespace std;
int main() {
  long long l, r, k, s = 1, j = 0;
  cin >> l >> r >> k;
  while (k) {
    if (s >= l && s <= r) {
      cout << (long long)s << " ";
      j++;
    } else if (s > r)
      break;
    s *= k;
  }
  if (j == 0) {
    cout << -1 << endl;
    return 0;
  }
}
