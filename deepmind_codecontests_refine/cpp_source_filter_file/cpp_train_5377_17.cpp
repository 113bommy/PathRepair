#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, ans = 0, i;
  cin >> n;
  for (i = 2; i <= n / 2; i++) {
    if ((n - i) % n == 0) ans++;
  }
  cout << ans + 1 << endl;
  return 0;
}
