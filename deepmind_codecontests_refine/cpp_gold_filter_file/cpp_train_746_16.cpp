#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, k;
  cin >> n >> k;
  k -= 1ll * n * (n + 1) / 2;
  if (k < 0) {
    puts("-1");
    return 0;
  }
  long long res = 1ll * n * (n + 1) / 2;
  vector<int> ans(n);
  for (int i = 0; i < n; ++i) ans[i] = i;
  for (int i = 0; i < n / 2; ++i) {
    if (k == 0) break;
    int j = min(n - i - 1, i + k);
    swap(ans[i], ans[j]);
    k -= j - i;
    res += j - i;
  }
  cout << res << "\n";
  for (int i = 0; i < n; ++i) cout << i + 1 << " \n"[i == n - 1];
  for (int i = 0; i < n; ++i) cout << ans[i] + 1 << " \n"[i == n - 1];
  return 0;
}
