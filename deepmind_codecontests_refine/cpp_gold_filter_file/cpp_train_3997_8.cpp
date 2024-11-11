#include <bits/stdc++.h>
using namespace std;
long long arr[100005], tree[100005], used[100005], BIT[100005], l[100005],
    r[100005], d[100005], b[100005], query[100005], x, y, n, m, k;
void update(long long s[], long long idx, long long val) {
  while (idx <= 100005) {
    s[idx] += val;
    idx += idx & (-idx);
  }
}
long long getS(long long s[], long l, long r) {
  if (l > r) {
    return 0;
  } else {
    if (l == 1) {
      long long res = 0;
      while (r > 0) {
        res += s[r];
        r -= r & (-r);
      }
      return res;
    } else {
      return getS(s, 1, r) - getS(s, 1, l - 1);
    }
  }
}
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> l[i] >> r[i] >> d[i];
  }
  for (int i = 0; i < k; i++) {
    cin >> x >> y;
    update(tree, x, 1);
    update(tree, y + 1, -1);
  }
  for (int i = 1; i <= m; i++) {
    used[i] = getS(tree, 1, i);
  }
  for (int i = 0; i < m; i++) {
    update(b, l[i], d[i] * used[i + 1]);
    update(b, r[i] + 1, -d[i] * used[i + 1]);
  }
  for (int i = 0; i < n; i++) {
    query[i + 1] = getS(b, 1, i + 1);
  }
  for (int i = 1; i <= n; i++) {
    cout << arr[i - 1] + query[i];
    if (i != n) {
      cout << " ";
    } else {
      cout << endl;
    }
  }
}
