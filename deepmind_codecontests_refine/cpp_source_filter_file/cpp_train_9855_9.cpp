#include <bits/stdc++.h>
using namespace std;
long long a[] = {0, 74, 7744, 777444, 77774444, 7777744444};
long long b[] = {0, 47, 4477, 444777, 44447777, 4444477777};
long long ans = 1e18;
void dfs(long long x, long long n, int L1, int L2) {
  if (L1 == 0 && L2 == 0) {
    if (x > n) ans = min(x, ans);
    return;
  }
  if (L1) dfs(x * 10 + 4, n, L1 - 1, L2);
  if (L2) dfs(x * 10 + 7, n, L1, L2 - 1);
}
int main() {
  long long n;
  cin >> n;
  long long x = n;
  int len = 0;
  while (x) {
    len++;
    x /= 10;
  }
  if (len & 1)
    cout << b[len / 2 + 1] << '\n';
  else {
    if (n > a[len / 2])
      cout << b[len / 2 + 1] << '\n';
    else {
      int L1 = len / 2, L2 = len / 2;
      dfs(0, n, L1, L2);
      cout << ans << '\n';
    }
  }
}
