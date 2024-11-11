#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n == 0)
    cout << 0;
  else {
    long long ans = 1;
    long long temp = 1LL * 3 * n * (n + 1);
    ans += temp;
    cout << ans;
  }
  return 0;
}
