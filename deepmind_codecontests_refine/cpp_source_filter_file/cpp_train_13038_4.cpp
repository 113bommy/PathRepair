#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  int tt;
  cin >> tt;
  while (tt--) {
    long long n, m;
    cin >> n >> m;
    long long ans = (n * m) / 2;
    if (n % 2 == 1 || m % 2 == 1) ans++;
    cout << ans << endl;
  }
  return 0;
}
