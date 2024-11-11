#include <bits/stdc++.h>
using namespace std;
void init() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int h[26];
void solve() {
  memset(h, 0, sizeof(h));
  int n, k;
  scanf("%d%d", &n, &k);
  vector<int> ds;
  for (int i = 2; i <= k; ++i)
    if (k % i == 0) ds.push_back(i);
  for (int i = 0; i < n; ++i) {
    char c;
    scanf(" %c", &c);
    ++h[c - 'a'];
  }
  int ans = 1;
  for (int d : ds) {
    for (int l = d; l <= n; l += d) {
      int cur = 0;
      for (int i = 0; i < 26; ++i) {
        cur += h[i] / (l / d);
      }
      if (cur >= d) ans = max(l, ans);
    }
  }
  printf("%d\n", ans);
}
int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
