#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
long long bit[200050];
long long a[200050];
int bits(int n) { return (-n) & n; }
void add(int p, long long v) {
  for (int i = p; i < 200050; i += bits(i)) {
    bit[i] += v;
  }
}
long long query(int p) {
  long long ans = 0;
  for (int i = p; i > 0; i -= bits(i)) {
    ans += bit[i];
  }
  return ans;
}
int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    add(i, a[i]);
  }
  while (q--) {
    int p, x;
    scanf("%d%d", &p, &x);
    add(p, x - a[p]);
    a[p] = x;
    int l = 1, r = n;
    long long t = 0, ans = -1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      long long temp = query(mid);
      if (temp < t) {
        l = mid + 1;
        t = temp * 2;
      } else
        r = mid;
      if (l == r) {
        if (query(l - 1) == a[l]) {
          ans = l;
          break;
        }
        if (l >= n) break;
        t = 2 * query(l++);
        r = n;
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
