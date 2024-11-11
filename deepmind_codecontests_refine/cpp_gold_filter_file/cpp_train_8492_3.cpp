#include <bits/stdc++.h>
using namespace std;
int a[200000], f[200000], cnt[200000], ans[200000], q[200000], n;
int get(int k) {
  if (f[k] != -1) return f[k];
  int res = 0, now = 0;
  for (int i = 1; i <= n; i++)
    if (cnt[a[i]] == 0) {
      if (now == k) {
        res++;
        while (now) {
          cnt[q[now--]] = 0;
        }
        now = 1;
        q[now] = a[i];
        cnt[a[i]] = 1;
      } else {
        cnt[a[i]] = 1;
        q[++now] = a[i];
      }
    }
  res += (now > 0);
  while (now) {
    cnt[q[now--]] = 0;
  }
  return f[k] = res;
}
void work(int l, int r) {
  if (l >= r || get(l) == get(r)) {
    for (int i = l; i <= r; i++) ans[i] = get(l);
    return;
  }
  int mid = (l + r) >> 1;
  work(l, mid);
  work(mid + 1, r);
}
int main() {
  memset(f, -1, sizeof f);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  work(1, n);
  for (int i = 1; i <= n; i++) cout << ans[i] << " ";
  return 0;
}
