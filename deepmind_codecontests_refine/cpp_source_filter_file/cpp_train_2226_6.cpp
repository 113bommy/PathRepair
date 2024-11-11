#include <bits/stdc++.h>
using namespace std;
int i, k, n, ans = 1;
int main() {
  cin >> n >> k;
  for (i = 1; i < k; i++) ans = ans * k % 1000000007;
  for (i = 1; i <= n - k; i++) ans = ans * (n - k) % 1000000007;
  cout << ans;
  return 0;
}
