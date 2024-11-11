#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, c;
  scanf("%d%d", &n, &c);
  int a, sisa;
  int ans;
  if (c % n) {
    a = c / n;
    sisa = c % n;
    ans = sisa * (a + 1) * (a + 1) + (n - sisa) * a * a;
  } else {
    a = c / n;
    ans = n * a * a;
  }
  cout << ans << "\n";
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
