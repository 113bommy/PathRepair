#include <bits/stdc++.h>
using namespace std;
long long calc(int n) {
  long long i = 1, ans = 0, k = n;
  while (n) {
    ans += i * (9 - n % 10);
    i *= 10;
    n /= 10;
  }
  return ans * k;
}
void solve() {
  long long l, r, ans = 0, i = 50000000L;
  cin >> l >> r;
  while (i && (l > i || r < i)) i /= 10;
  if (i) ans = max(calc(i), ans);
  ans = max(calc(l), ans);
  ans = max(calc(r), ans);
  cout << ans << endl;
}
int main() {
  solve();
  return 0;
}
