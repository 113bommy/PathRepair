#include <bits/stdc++.h>
using namespace std;
struct key_val {
  long long val;
  long long key;
};
bool comp(key_val a, key_val b) { return a.val < b.val; }
key_val skill[100007];
long long sum[100007], q[100007], b[100007];
int main() {
  long long n, A, cf, cm, m, l, r, left, i, mid, x,
      ans = numeric_limits<long long>::min(), perfect, low, p;
  cin >> n >> A >> cf >> cm >> m;
  for (i = 1; i <= n; i++) {
    cin >> skill[i].val;
    skill[i].key = i;
    q[i] = skill[i].val;
  }
  sort(skill + 1, &skill[n + 1], comp);
  sum[1] = skill[1].val;
  b[1] = skill[1].val;
  for (i = 2; i <= n; i++) {
    sum[i] = sum[i - 1] + skill[i].val;
    b[i] = skill[i].val;
  }
  for (i = n; i >= 0; i--) {
    left = (n - i) * A - (sum[n] - sum[i]);
    left = m - left;
    if (left < 0) {
      break;
    }
    l = 0;
    r = A;
    while (l < r) {
      mid = l + r + 1 >> 1;
      x = lower_bound(b + 1, b + i + 1, mid) - b - 1;
      if (x * mid - sum[x] <= left) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    if (cf * (n - i) + cm * l > ans) {
      ans = cf * (n - i) + cm * l;
      perfect = i;
      low = l;
    }
  }
  for (p = 1; p <= n; p++) {
    if (q[p] < l) {
      q[p] = l;
    }
  }
  while (perfect + 1 <= n) {
    q[skill[perfect + 1].key] = A;
    perfect++;
  }
  cout << ans << "\n";
  for (i = 1; i <= n; i++) {
    cout << q[i] << " ";
  }
  return 0;
}
