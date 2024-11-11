#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, ans = 0, i;
  cin >> n;
  for (i = 1; i <= n / 2; i++) {
    if ((n - i) % i == 0) ans++;
  }
  cout << ans << endl;
  return 0;
}
