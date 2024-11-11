#include <bits/stdc++.h>
using namespace std;
int a[100005];
int b[100005];
int main() {
  int n, m, q;
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < m; i++) scanf("%d", &b[i]);
  set<long long> s;
  long long now = 0;
  for (int i = 0; i < n; i++) {
    if (i & 1)
      now -= a[i];
    else
      now += a[i];
  }
  long long temp = 0;
  for (int i = 0; i < n - 1; i++) {
    if (i & 1)
      temp -= b[i];
    else
      temp += b[i];
  }
  for (int i = n - 1; i < m; i++) {
    if (n & 1)
      temp += b[i];
    else
      temp -= b[i];
    s.insert(temp);
    temp -= b[i - n + 1];
    temp = -temp;
  }
  for (int i = 0; i <= q; i++) {
    if (i != 0) {
      int l, r, first;
      scanf("%d %d %d", &l, &r, &first);
      if ((l - r + 1) % 2 == 1) {
        if (l & 1) {
          now -= first;
        } else {
          now += first;
        }
      }
    }
    set<long long>::iterator it = s.lower_bound(now);
    long long ans = 1e18;
    if (it != s.end()) {
      ans = min(*it - now, ans);
    }
    if (it != s.begin()) {
      it--;
      ans = min(now - *it, ans);
    }
    printf("%I64d\n", ans);
  }
}
