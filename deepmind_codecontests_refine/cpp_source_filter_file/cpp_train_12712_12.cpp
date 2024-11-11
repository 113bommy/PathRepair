#include <bits/stdc++.h>
using namespace std;
int n, a[1001], s, ans;
int main(int argc, char const *argv[]) {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) {
    s = 0;
    for (int j = i; j <= n; ++j) {
      s += a[j];
      if (s > (j - i + 1) * 100) ans = max(ans, j - i + 1);
    }
  }
  cout << ans;
  return 0;
}
