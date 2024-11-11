#include <bits/stdc++.h>
const int N = 500005;
int n;
long long a[N], b[N], s;
struct basic {
  int cnt;
  long long a[70];
  void insert(int x) {
    for (int i = 60; i >= 0; i--) {
      if ((x & (1ll << i)) == 0) continue;
      if (!a[i]) {
        if (x & (1ll << i)) {
          cnt++, a[i] = x;
          break;
        }
      } else
        x ^= a[i];
    }
  }
  bool fill() {
    long long x = s;
    for (int i = 60; i >= 0; i--) x ^= a[i];
    return (!x);
  }
} t;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld%lld", &a[i], &b[i]);
    s ^= a[i];
    b[i] = a[i] ^ b[i];
  }
  for (int i = 1; i <= n; i++) t.insert(b[i]);
  int cnt = t.cnt;
  t.insert(s);
  if (cnt == t.cnt) {
    printf("%lld/%lld", (1ll << (t.cnt)) - 1, 1ll << t.cnt);
  } else
    puts("1/1");
}
