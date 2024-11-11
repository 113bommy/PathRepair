#include <bits/stdc++.h>
using namespace std;
long long s[1000007], res, n, k;
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) scanf("%I64d", &s[i]);
  res = 1e18;
  for (int i = 1; i <= n - k; i++)
    res = min(res, s[i] + s[(n - k) * 2 - i + 1]);
  for (int i = 1; i <= n; ++i) res = max(res, s[i]);
  cout << res;
}
