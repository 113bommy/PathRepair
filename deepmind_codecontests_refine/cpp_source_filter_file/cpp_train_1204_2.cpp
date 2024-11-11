#include <bits/stdc++.h>
using namespace std;
int n, m;
int k[123123];
int cnt[123123];
int a[123123];
map<int, unordered_set<int> > fuck;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    int p = 2;
    while (p * p <= x) {
      if (x % p == 0) {
        cnt[p]++;
        while (x % p == 0) x /= p;
      } else
        p++;
    }
    if (x > 1) cnt[x]++;
  }
  for (int i = 0; i <= n; i++) {
    ans = max(ans, cnt[i]);
  }
  cout << ans;
  return 0;
}
