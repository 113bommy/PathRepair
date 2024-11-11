#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  int l, r, a;
  cin >> l >> r >> a;
  int ans = 0;
  for (int i = 0; i <= a; i++) ans = max(ans, min(l + i, r + a - i));
  cout << 2 * ans;
  return 0;
}
