#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int n, d, e;
  cin >> n >> d >> e;
  e *= 5;
  int ret = n;
  for (int i = 0; i <= n; i += d) {
    int rem = n - i;
    rem %= e;
    ret = min(ret, rem);
  }
  cout << ret << endl;
  return 0;
}
