#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int a, b, k;
    cin >> a >> b >> k;
    long long int ans;
    ans = (k / 2) * (a - b) + (k % 2) * a;
    cout << ans << endl;
  }
}
