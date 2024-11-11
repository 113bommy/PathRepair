#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, k, l;
  cin >> n >> m >> k >> l;
  long long ans = (l + k) / m - 1;
  if (ans * m > n) ans = -1;
  cout << ans;
  return 0;
}
