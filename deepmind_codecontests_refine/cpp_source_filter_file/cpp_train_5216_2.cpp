#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<long long> a(n);
  for (auto &x : a) {
    cin >> x;
  }
  int ans = 1;
  int i = 0, j = 0;
  while (i < n) {
    j = max(i, j);
    while (j < n) {
      if (j + 1 < n && a[j + 1] <= a[i] * 2) {
        ++j;
      } else {
        break;
      }
    }
    ans = max(ans, j - i + 1);
    ++i;
  }
  cout << ans;
  return 0;
}
