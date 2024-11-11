#include <bits/stdc++.h>
using namespace std;
const int max_n = 40;
set<int> mark;
int a[max_n];
int n, k, ans;
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  int tmp = (1 << (n / 2));
  for (int i = 0; i < tmp; i++) {
    int x = 0;
    for (int j = 0; j < n / 2; j++) {
      if ((i >> j) & 1) x += a[j], x %= k;
    }
    mark.insert(x);
  }
  tmp = (1 << (n - n / 2));
  for (int i = 0; i < tmp; i++) {
    int x = 0;
    for (int j = 0; j < n - n / 2; j++) {
      if ((i >> j) & 1) x += a[j + n / 2], x %= k;
    }
    int p = *(--mark.lower_bound(k - x));
    ans = max(ans, (p + x) % k);
  }
  cout << ans;
  return 0;
}
