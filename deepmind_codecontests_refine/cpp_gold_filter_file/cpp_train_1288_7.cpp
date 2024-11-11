#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ul = unsigned;
using db = double;
int n, k;
const int maxn = 1000001;
int res[maxn];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> k;
  if (k * 3 > n || n == 3) return cout << -1 << '\n', 0;
  if (k & 1) {
    for (int i = 2, l = 2; i <= k; ++i, l += 6) {
      res[l] = res[l + 2] = res[l + 3] = i++;
      res[l + 1] = res[l + 4] = res[l + 5] = i;
    }
  } else {
    for (int i = 1, l = 1; i <= k; ++i, l += 6) {
      res[l] = res[l + 2] = res[l + 3] = i++;
      res[l + 1] = res[l + 4] = res[l + 5] = i;
    }
  }
  for (int i = 1; i <= n; ++i) cout << max(1, res[i]) << " \n"[n == i];
}
