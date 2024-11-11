#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long ans = 0;
  for (int i = 2; i <= n / 2; ++i) {
    int tep = n / i;
    ans += 1ll * (tep * (tep + 1) / 2 - 1) * 4;
  }
  cout << ans;
  return 0;
}
