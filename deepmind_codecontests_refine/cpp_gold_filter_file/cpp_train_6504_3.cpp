#include <bits/stdc++.h>
using namespace std;
void timo() {
  ios::sync_with_stdio(0);
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
}
int main() {
  timo();
  int n, a[2050] = {0}, ans = 0;
  cin >> n;
  for (int i = 2; i <= (1 << n + 1) - 1; i++) {
    cin >> a[i];
  }
  for (int i = (1 << n) - 1; i >= 1; i--) {
    ans += abs(a[i * 2] - a[i * 2 + 1]);
    int maxlan = max(a[i * 2], a[i * 2 + 1]);
    a[i] += a[i * 2] = a[i * 2 + 1] = maxlan;
  }
  cout << ans << endl;
  return 0;
}
