#include <bits/stdc++.h>
using namespace std;
const int N = 1000 * 100 + 10;
pair<int, int> a[N];
int b[N], n;
long long tr[3][N * 4];
long long fn(bool state, int l, int r, int b = 0, int e = n, int ind = 1) {
  long long ret = 0;
  if (l <= b && e <= r) return tr[state][ind];
  int mid = (b + e) / 2;
  if (l < mid) ret += fn(state, l, r, b, mid, ind * 2);
  if (r > mid) ret += fn(state, l, r, mid, e, ind * 2 + 1);
  return ret;
}
void add(int state, int p, int val, int b = 0, int e = n, int ind = 1) {
  tr[state][ind]++;
  if (b + 1 == e) return;
  int mid = (b + e) / 2;
  if (p < mid)
    add(state, p, val, b, mid, ind * 2);
  else
    add(state, p, val, mid, e, ind * 2 + 1);
  return;
}
long long rec(int val) {
  return (fn(1, 0, val) + ((val + 1 == n) ? 0 : fn(0, val + 1, n)));
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int pt = -1;
  long long k, ans = 0, num = 0;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a, a + n);
  for (int i = 0; i < n; i++) {
    if (!i || a[i].first != a[i - 1].first)
      b[a[i].second] = ++pt;
    else
      b[a[i].second] = pt;
  }
  add(1, b[n - 1], 1);
  pt = 0;
  long long temp = rec(b[pt]);
  while (pt < n - 1 && temp + num <= k) {
    add(0, b[pt], 1);
    num += temp;
    temp = rec(b[++pt]);
  }
  ans += pt;
  pt--;
  for (int i = n - 2; i > 0; i--) {
    num += rec(b[i]);
    add(1, b[i], 1);
    while (pt >= 0 && (num > k || pt >= i)) {
      add(0, b[pt], -1);
      num -= rec(b[pt--]);
    }
    ans += pt + 1;
  }
  cout << ans << endl;
  return 0;
}
