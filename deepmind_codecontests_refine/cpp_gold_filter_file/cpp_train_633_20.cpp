#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, ans = 0;
  cin >> n;
  for (int i = 2; i <= n; i++) {
    for (int j = 2 * i; j <= n; j += i) ans = ans + 4 * (j / i);
  }
  cout << ans << endl;
}
