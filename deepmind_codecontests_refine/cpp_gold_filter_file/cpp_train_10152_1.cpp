#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long long l, r, k, i;
  bool bul;
  cin >> l >> r >> k;
  i = 1;
  bul = 0;
  while (i <= r) {
    if (i >= l && i <= r) cout << i << " ", bul = 1;
    if (i > 1000000000000000000 / k)
      break;
    else
      i = i * k;
  }
  if (bul == 0) cout << -1 << endl;
  return 0;
}
