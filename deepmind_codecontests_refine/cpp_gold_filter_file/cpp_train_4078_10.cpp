#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int a, b;
  cin >> a >> b;
  int k = a + b;
  long long ans = 1;
  while (k--) {
    ans = (ans * 2) % 998244353;
    ans = ans % 998244353;
  }
  cout << ans << endl;
  return 0;
}
