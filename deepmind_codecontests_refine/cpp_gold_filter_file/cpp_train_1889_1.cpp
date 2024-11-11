#include <bits/stdc++.h>
using namespace std;
int main() {
  srand(31415);
  ios::sync_with_stdio(0);
  int n, x;
  cin >> n;
  long long ans = 0, C = 0, k;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    while (C > 0 && x > 1 && x % 3 != 0) {
      C--;
      x -= 2;
      ans++;
    }
    k = min(C / 3ll, x / 6ll);
    C -= 3 * k;
    x -= 6 * k;
    ans += 3 * k;
    C += x % 3;
    ans += x / 3;
  }
  cout << ans << "\n";
  return 0;
}
