#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n == 0)
    cout << 1;
  else {
    long long ans = 1LL;
    long long temp = 1LL * 3 * n * (n + 1);
    ans += temp;
    cout << ans;
  }
  return 0;
}
