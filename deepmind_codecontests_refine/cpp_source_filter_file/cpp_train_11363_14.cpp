#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i;
  cin >> n;
  long long int ans = 0;
  for (i = 2; i <= n; i++) {
    ans += 1 * i * (i + 1);
  }
  cout << ans << endl;
  return 0;
}
