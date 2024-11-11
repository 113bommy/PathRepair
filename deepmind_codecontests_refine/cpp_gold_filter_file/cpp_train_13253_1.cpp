#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m, k;
  cin >> n >> m >> k;
  if (k == 1 || k > n) {
    long long ans = 1;
    for (int i = 0; i < n; i++) ans = (ans * m) % 1000000007;
    cout << ans << endl;
  } else if (n == k) {
    long long ans = 1;
    for (int i = 0; i < (n + 1) / 2; i++) {
      ans = (ans * m) % 1000000007;
    }
    cout << ans << endl;
  } else if (k % 2 == 0)
    cout << m << endl;
  else
    cout << m * m << endl;
  return 0;
}
