#include <bits/stdc++.h>
using namespace std;
int main() {
  int l, r, a;
  cin >> l >> r >> a;
  int ans = 0;
  while (a > 0) {
    if (l < r)
      l++;
    else
      r++;
    --a;
    ans = min(l, r);
  }
  cout << ans * 2 << endl;
}
