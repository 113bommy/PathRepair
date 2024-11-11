#include <bits/stdc++.h>
using namespace std;
int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};
int a[300002], n, ans;
void insert(int i) {
  if (i == 0 || i == n + 1) return;
  if (a[i] > a[i - 1] && a[i] > a[i + 1])
    ans += a[i];
  else if (a[i] < a[i - 1] && a[i] < a[i + 1])
    ans -= a[i];
}
void erase(int i) {
  if (i == 0 || i == n + 1) return;
  if (a[i] > a[i - 1] && a[i] > a[i + 1])
    ans -= a[i];
  else if (a[i] < a[i - 1] && a[i] < a[i + 1])
    ans += a[i];
}
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  std::cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    a[0] = a[n + 1] = -1;
    ans = 0;
    for (int i = 1; i <= n; ++i) {
      if (a[i] > a[i - 1] && a[i] > a[i + 1])
        ans += a[i];
      else if (a[i] < a[i - 1] && a[i] < a[i + 1])
        ans -= a[i];
    }
    cout << ans << '\n';
    while (q--) {
      int l, r;
      cin >> l >> r;
      if (l == r) {
        cout << ans << '\n';
        continue;
      }
      erase(l - 1);
      erase(l);
      erase(l + 1);
      if (r - 1 != l && r - 1 != l + 1) erase(r - 1);
      if (r != l + 1) erase(r);
      erase(r + 1);
      swap(a[l], a[r]);
      insert(l - 1);
      insert(l);
      insert(l + 1);
      if (r - 1 != l && r - 1 != l + 1) insert(r - 1);
      if (r != l + 1) insert(r);
      insert(r + 1);
      cout << ans << '\n';
    }
  }
  return 0;
}
