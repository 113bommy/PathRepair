#include <bits/stdc++.h>
using namespace std;
const int MAXN = 210;
int n, a[MAXN];
int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < 2 * n; ++i) cin >> a[i];
  int ans = 0;
  for (int i = 0; i < 2 * n; i += 2) {
    int j = i + 1;
    while (j < 2 * n) {
      if (a[j] == a[i]) {
        break;
      }
      ++j;
    }
    if (j == 2 * n) break;
    while (j > i + 1) {
      swap(a[j], a[j - 1]);
      ++ans;
      --j;
    }
  }
  cout << ans;
  return 0;
}
