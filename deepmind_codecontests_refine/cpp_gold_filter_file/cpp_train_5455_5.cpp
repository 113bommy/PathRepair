#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  long long N1, N2;
  long long ans = 0;
  cin >> n >> m >> k;
  N1 = (n - 1) % k;
  N2 = (m - 1) % k;
  ans = ((n - N1 - 1) / k + 1) * ((m - N2 - 1) / k + 1) * (N1 + 1) * (N2 + 1);
  cout << ans;
  return 0;
}
