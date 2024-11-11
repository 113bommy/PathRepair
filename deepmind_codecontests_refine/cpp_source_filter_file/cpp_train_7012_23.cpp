#include <bits/stdc++.h>
using namespace std;
long long int n, m, a[100010] = {1}, ans = 1;
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) a[i] = (a[i - 1] * 2) % (long long int)(1e9 + 7);
  for (int i = 0; i < n; i++)
    ans *= a[m] - (i + 1), ans %= (long long int)(1e9 + 7);
  cout << ans << endl;
  return 0;
}
