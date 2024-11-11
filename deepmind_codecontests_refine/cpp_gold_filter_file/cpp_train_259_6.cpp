#include <bits/stdc++.h>
using namespace std;
const int N = 30010;
struct note {
  int val;
  int id;
  bool operator<(const note &x) const { return val < x.val; }
};
inline void read(int &x) {
  x = 0;
  int f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') {
      f = -1;
    }
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  x *= f;
}
note a[N];
int n, m, q;
int fib[N], l[N], r[N], max_n[N], cnt[N];
long long ans[N];
int main() {
  read(n), read(m);
  for (int i = 1; i <= n; i++) {
    read(a[i].val);
    a[i].id = i;
  }
  sort(a + 1, a + n + 1);
  fib[1] = fib[2] = 1;
  for (int i = 3; i <= n; i++) {
    fib[i] = (fib[i - 1] + fib[i - 2]) % m;
  }
  read(q);
  for (int i = 1; i <= q; i++) {
    read(l[i]), read(r[i]);
    max_n[i] = -1;
  }
  for (int i = 1; i <= n; i++) {
    int x = a[i].val % m;
    for (int j = 1; j <= q; j++) {
      if (a[i].id >= l[j] && a[i].id <= r[j] && a[i].val != max_n[j]) {
        max_n[j] = a[i].val;
        ans[j] += fib[++cnt[j]] * x;
      }
    }
  }
  for (int i = 1; i <= q; i++) {
    printf("%lld\n", ans[i] % m);
  }
  return 0;
}
