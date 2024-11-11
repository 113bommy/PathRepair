#include <bits/stdc++.h>
using namespace std;
long long ans, i, t, n;
int main() {
  cin >> n;
  ans = 0;
  t = 3;
  for (i = 1; i < n; i++) {
    ans = (ans * 3 + t) % 1000000007;
    t *= (-1);
  }
  cout << ans;
  return 0;
}
