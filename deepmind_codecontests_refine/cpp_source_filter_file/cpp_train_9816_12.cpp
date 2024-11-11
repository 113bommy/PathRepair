#include <bits/stdc++.h>
using namespace std;
long long n, q, pre[1000000], a[1000000], f[100], vis[100], ans, rec[100],
    temp[100];
int main() {
  cin >> n >> q;
  for (long long i = n; i >= 1; i--) pre[i] = pre[i + 1] + n - i + 1;
  f[0] = 1;
  for (long long i = 1; i <= 20; i++) f[i] = f[i - 1] * i;
  long long num = 0;
  for (long long o = 1; o <= q; o++) {
    long long tag;
    cin >> tag;
    if (tag == 1) {
      long long l, r;
      cin >> l >> r;
      if (r > 20) {
        cout << pre[n - r + 1] - pre[n - l + 2] << endl;
        continue;
      }
      long long t = num;
      for (long long i = min(n, (long long)20); i >= 1; i--)
        if (t >= f[i - 1]) {
          rec[i] = t / f[i - 1] + 1;
          t = t % f[i - 1];
        } else
          rec[i] = 1;
      memset(vis, 0, sizeof vis);
      long long base = n - 20;
      if (n <= 20) base = 0;
      for (long long i = min(n, (long long)20); i >= 1; i--) {
        long long xx, cnt = 0, now = 1;
        while (cnt < rec[i]) {
          if (!vis[now]) cnt++;
          now++;
        }
        now--;
        temp[i] = now + base;
        vis[now] = 1;
      }
      for (int i = min(n, (long long)20); i >= 1; i--)
        pre[i] = pre[i + 1] + temp[i];
      cout << pre[n - r + 1] - pre[n - l + 2] << endl;
    } else {
      long long x;
      cin >> x;
      num += x;
    }
  }
}
