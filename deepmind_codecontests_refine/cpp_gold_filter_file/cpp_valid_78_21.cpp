#include <bits/stdc++.h>
using namespace std;
void solve() {
  int l, r;
  scanf("%d%d", &l, &r);
  int x = (r - 1) / 2;
  if (x + 1 >= l)
    printf("%d\n", x);
  else
    printf("%d\n", r % l);
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
