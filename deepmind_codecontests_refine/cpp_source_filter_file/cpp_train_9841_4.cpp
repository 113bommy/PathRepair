#include <bits/stdc++.h>
using namespace std;
int read() {
  int f = 1, x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = x * 10 + (s - '0');
    s = getchar();
  }
  return x * f;
}
int n, m, i, j, s, o, k, b, c;
long long sum[200005];
int a[200005], q2[200005], q[200005];
int cnt, cnt2;
priority_queue<long long> st;
int main() {
  n = read();
  k = read();
  b = read();
  c = read();
  for (int i = 1; i <= n; i++) {
    a[i] = read();
  }
  sort(a + 1, a + 1 + n);
  if (b >= 5 * c) {
    for (int i = 1; i <= n; i++) {
      sum[i] = sum[i - 1] + a[i];
    }
    long long ans = 1e16;
    for (int i = k; i <= n; i++) {
      ans = min(ans, (k * 1ll * a[i] - sum[i] + sum[i - k]) * c);
    }
    printf("%lld\n", ans);
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 5; j++) {
      q2[++cnt2] = a[i] + j;
    }
  }
  sort(q2 + 1, q2 + 1 + cnt2);
  q2[0] = -0x7f7f7f7f;
  for (int i = 1; i <= cnt2; i++) {
    if (q2[i] > q2[i - 1]) {
      q[++cnt] = q2[i];
    }
  }
  long long ans = 1e18;
  for (int re = 0; re < 5; re++) {
    int pn = 0, ct = 0;
    long long ad = 0;
    long long as = 0;
    while (!st.empty()) st.pop();
    for (int i = 1; i <= cnt; i++) {
      if ((q[i] % 5 + 5) % 5 == re) {
        ad += int((q[i] - pn) / 5ll) * 1ll * b;
        if (st.empty()) ad = 0;
        while (ct <= n && a[ct + 1] <= q[i]) {
          ct++;
          int nm = q[i] - a[ct];
          long long cs = (int(nm / 5ll) * 1ll * b + (nm % 5ll) * c) + 0ll - ad;
          st.push(cs);
          as += cs;
        }
        while (st.size() > k) {
          as -= st.top();
          st.pop();
        }
        if (st.size() == k) {
          ans = min(ans, as + ad * 1ll * k);
        }
        pn = q[i];
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}
