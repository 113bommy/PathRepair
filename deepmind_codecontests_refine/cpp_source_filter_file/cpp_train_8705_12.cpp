#include <bits/stdc++.h>
using namespace std;
int stg[17], n, m, drp[17];
multiset<int> a, b;
multiset<int>::iterator c;
int main() {
  int sum;
  cin >> n >> m;
  for (int i = 1; i <= n / 2; i++) cin >> stg[i];
  for (int i = n / 2 + 1; i <= n; i++) cin >> drp[i - n / 2];
  for (int i = 0; i < (1 << (n / 2)); i++) {
    sum = 0;
    for (int j = 0; j < (n / 2); j++)
      if ((i & (1 << j))) {
        sum += stg[j + 1];
        sum %= m;
      }
    a.insert(sum);
  }
  for (int i = 0; i < (1 << (n / 2 + n % 2)); i++) {
    sum = 0;
    for (int j = 0; j < (n / 2 + n % 2); j++)
      if ((i & (1 << j))) {
        sum += drp[j + 1];
        sum %= m;
      }
    b.insert(sum);
  }
  int ans = 0;
  for (auto &it : a) {
    c = b.upper_bound(m - it - 1);
    --c;
    ans = max(ans, (*c + it) % m);
  }
  cout << ans << "\n";
  return 0;
}
