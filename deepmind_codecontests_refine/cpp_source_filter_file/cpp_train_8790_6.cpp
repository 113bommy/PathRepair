#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j;
  long long n, m, K;
  cin >> n >> m >> K;
  if (K > (n - 1) * (m - 1)) {
    cout << -1 << endl;
    return 0;
  }
  long long ans = 0;
  if (n < m) swap(n, m);
  if (K <= (n - 1)) {
    ans = ((n) / (K + 1)) * m;
    ans = max(ans, m / (K + 1) * n);
  } else {
    long long rest = K - (n - 1);
    ans = (m / (rest + 1));
  }
  cout << ans << endl;
  return 0;
}
