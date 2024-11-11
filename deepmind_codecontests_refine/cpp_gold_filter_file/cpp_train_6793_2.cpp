#include <bits/stdc++.h>
using namespace std;
int cnt[4001];
int f(int x, int n, int p) {
  int c = 0;
  for (int i = 1; i <= x; i++) {
    c += cnt[i];
  }
  int ans = c % p;
  c--;
  for (int i = 2; i <= n; i++) {
    x++;
    c += cnt[x];
    ans = (ans * c) % p;
    c--;
  }
  return (ans > 0);
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int p, n;
  cin >> n >> p;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  sort(a.begin(), a.end());
  int min_x = 0;
  for (int i = 0; i < n; i++) {
    min_x = max(min_x, a[i] - i);
  }
  vector<int> ans;
  for (int i = min_x; i <= 2000; i++) {
    if (f(i, n, p)) ans.push_back(i);
  }
  cout << ans.size() << '\n';
  for (int i : ans) cout << i << ' ';
  return 0;
}
