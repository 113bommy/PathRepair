#include <bits/stdc++.h>
using namespace std;
int a[200005], n;
long long aj[200005];
pair<long long, long long> st2[4 * 200005];
void init(int _n) {
  n = 1;
  while (n < _n) n *= 2;
}
long long q2(int a, int b, int k, int l, int r) {
  if (r < a || b < l)
    return 0;
  else if (a <= l && r <= b)
    return st2[k].first + st2[k].second * (r - l + 1);
  else {
    int m = (l + r) / 2, lson = k * 2, rson = k * 2 + 1;
    long long res = (min(b, r) - max(a, l) + 1) * st2[k].second;
    res += q2(a, b, lson, l, m) + q2(a, b, rson, m + 1, r);
    return res;
  }
}
void update2(int a, int b, long long x, int k, int l, int r) {
  if (r < a || b < l)
    return;
  else if (a <= l && r <= b)
    st2[k].second += x;
  else {
    int m = (l + r) / 2, lson = k * 2, rson = k * 2 + 1;
    st2[k].first += (min(b, r) - max(a, l) + 1) * x;
    st2[lson].second += st2[k].second, st2[rson].second += st2[k].second;
    st2[k].second = 0;
    update2(a, b, x, lson, l, m);
    update2(a, b, x, rson, m + 1, r);
  }
}
int main() {
  int _n, m;
  cin >> _n >> m;
  init(_n);
  for (int i = 0; i < m; i++) cin >> a[i];
  for (int i = 0; i < m - 1; i++) {
    if (a[i] == a[i + 1]) continue;
    if (a[i] > a[i + 1])
      update2(a[i + 1] + 1, a[i] - 1, 1, 1, 1, n);
    else
      update2(a[i] + 1, a[i + 1] - 1, 1, 1, 1, n);
  }
  for (int i = 0; i < m - 1; i++) {
    if (a[i] == a[i + 1]) continue;
    if (a[i] < a[i + 1])
      aj[a[i]] += (a[i + 1] - 1) - (a[i + 1] - a[i]);
    else if (a[i] > a[i + 1])
      aj[a[i]] += a[i + 1] - (a[i] - a[i + 1]);
    if (a[i + 1] < a[i])
      aj[a[i + 1]] += (a[i] - 1) - (a[i] - a[i + 1]);
    else if (a[i + 1] > a[i])
      aj[a[i + 1]] += a[i] - (a[i + 1] - a[i]);
  }
  int ans = 0;
  for (int i = 0; i < m - 1; i++) ans += abs(a[i] - a[i + 1]);
  cout << ans << " ";
  for (int i = 2; i <= _n; i++) {
    cout << ans + aj[i] - q2(i, i, 1, 1, n) << " ";
  }
}
