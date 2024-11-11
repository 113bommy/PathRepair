#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int ans = n / 10;
    if (n % 10 == 9) ans++;
    cout << ans << endl;
  }
  return 0;
}
