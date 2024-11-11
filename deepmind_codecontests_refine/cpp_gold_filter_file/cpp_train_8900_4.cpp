#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9 + 7;
int main() {
  int n;
  scanf("%d", &n);
  vector<int> h(n, 0);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &h[i]);
  }
  vector<int> pref(n, 0);
  vector<int> suff(n, inf);
  pref[0] = h[0];
  suff[n - 1] = h[n - 1];
  for (int i = 1; i < n; ++i) {
    pref[i] = max(pref[i - 1], h[i]);
  }
  for (int i = n - 2; i >= 0; --i) {
    suff[i] = min(suff[i + 1], h[i]);
  }
  int ans = 1;
  for (int i = 0; i < n - 1; ++i) {
    if (pref[i] <= suff[i + 1]) {
      ++ans;
    }
  }
  printf("%d", ans);
  return 0;
}
