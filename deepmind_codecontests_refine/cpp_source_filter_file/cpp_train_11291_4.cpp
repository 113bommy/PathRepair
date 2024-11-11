#include <bits/stdc++.h>
using namespace std;
int st[100050][50], Log[100050], a[100050], n;
map<int, int> sum;
int gcd(int x, int y) { return y == 0 ? x : gcd(y, x % y); }
int query(int x, int y) {
  int k = Log[y - x + 1];
  return gcd(st[x][k], st[y - (1 << k) + 1][k]);
}
int find(int g, int l, int L) {
  int r = n, ans = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (query(L, mid) == g)
      ans = mid, l = mid + 1;
    else
      r = mid - 1;
  }
  return ans;
}
void solve(int x) {
  int lst = x, now = x, t = st[x][0];
  while (1) {
    lst = now;
    now = find(t, lst, x);
    if (sum[t]) sum[t] += (now - lst + 1);
    if (now == n) return;
    now++;
    t = query(x, now);
  }
}
int main() {
  cin >> n;
  Log[1] = 0;
  for (int i = 2; i <= n; i++) Log[i] = Log[i >> 1] + 1;
  int mx = Log[n];
  for (int i = 1; i <= n; i++) cin >> st[i][0];
  for (int i = 1; i <= mx; i++) {
    for (int j = 1; j + (1 << i) - 1 <= n; j++) {
      st[j][i] = gcd(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
    }
  }
  int q;
  cin >> q;
  for (int i = 1; i <= q; i++) {
    cin >> a[i];
    sum[a[i]] = 1;
  }
  for (int i = 1; i <= n; i++) solve(i);
  for (int i = 1; i <= q; i++) cout << sum[a[i]] - 1 << endl;
  return 0;
}
