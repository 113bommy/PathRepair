#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, ans;
  cin >> n;
  ans = ceil(n / 2.0);
  if (ans % 2 == 0) ans++;
  cout << ans;
  return 0;
}
