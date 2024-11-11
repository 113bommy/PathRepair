#include <bits/stdc++.h>
using namespace std;
vector<int> neg(vector<int> v) {
  for (int i = 0; i < v.size(); i++) v[i] = -v[i];
  return v;
}
int n;
int a[1001];
map<vector<int>, int> mp;
vector<vector<int> > v1, v2;
int cnt[101];
int count(int x) {
  int ans = 0;
  while (x) ans += x & 1, x >>= 1;
  return ans;
}
vector<int> build(int x, int add) {
  for (int i = 1; i <= n; i++) {
    int cur;
    if (add == 0)
      cur = a[i] & ((1 << 16) - 1);
    else
      cur = a[i] & ((1ll << 31) - (1 << 15));
    cnt[i] = count(cur ^ x);
  }
  vector<int> v;
  v.resize(n);
  for (int i = 1; i < n; i++) v[i] = cnt[i] - cnt[i + 1];
  return v;
}
signed main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < (1 << 15); i++) {
    memset(cnt, 0, sizeof(cnt));
    mp[build(i, 0)] = i;
  }
  for (int i = 0; i < (1 << 15); i++) {
    vector<int> cur = build(i << 15, 1);
    if (mp[neg(cur)]) {
      printf("%d", (i << 15) + mp[neg(cur)]);
      return 0;
    }
  }
  printf("-1");
  return 0;
}
