#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1 << 20;
long long a, b;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> a >> b;
  long long ans = 0;
  while (a && b) {
    if (a < b) {
      swap(a, b);
    }
    ans += a / b;
    a %= b;
  }
  cout << ans << endl;
  return 0;
}
