#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 * 100 + 10;
long long n, k, ans;
int a[MAXN];
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  for (int i = 0; i <= k; i++) ans += a[i];
  cout << ans << '\n';
  return 0;
}
