#include <bits/stdc++.h>
using namespace std;
string ltob(long long x) {
  string ss;
  while (x) {
    ss += (x & 1) + '0';
    x >>= 1;
  }
  reverse(ss.begin(), ss.end());
  return ss;
}
int main() {
  int n;
  scanf("%d", &n);
  long long er[100] = {0};
  er[0] = 1;
  for (int i = 1; i <= 59; i++) {
    er[i] = er[i - 1] * 2;
  }
  while (n--) {
    long long l, r;
    scanf("%lld %lld", &l, &r);
    string a, b;
    a = ltob(l);
    b = ltob(r);
    long long ans = 0;
    if (b.size() > a.size()) {
      long long tp = 1;
      for (int i = 0; i < b.size() - 1; i++) {
        ans += tp;
        tp *= 2;
      }
      if (ans + er[b.size() - 1] <= r) ans += er[b.size() - 1];
    } else if (a.size() == b.size()) {
      bool f = 1;
      long long j;
      for (int i = 0; i < a.size(); i++) {
        if (a[i] == b[i] && f) {
          ans += (a[i] - '0') * er[a.size() - i - 1];
        } else if (a[i] != b[i] && f) {
          f = 0;
          ans += er[a.size() - i - 1];
          j = er[a.size() - i - 1];
        } else if (!f)
          ans += er[a.size() - i - 1];
      }
      if (ans > r) {
        ans -= j;
      }
    }
    printf("%lld\n", ans);
  }
}
