#include <bits/stdc++.h>
using namespace std;
long long n, t;
long long a[200010], b[200010];
long long pre[200010];
long long tr[200010] = {0};
long long ask(long long x) {
  long long ans = 0;
  for (; x; x -= x & -x) ans += tr[x];
  return ans;
}
void add(long long x) {
  for (; x < 200000; x += x & -x) tr[x]++;
}
int main() {
  scanf("%lld%lld", &n, &t);
  long long sum = 0;
  pre[0] = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &b[i]);
    pre[i] = pre[i - 1] + b[i];
    a[i] = pre[i];
  }
  sort(a + 1, a + 2 + n);
  int len = unique(a + 1, a + 2 + n) - a - 1;
  for (int i = 0; i <= n; i++) {
    pre[i] = lower_bound(a + 1, a + 1 + len, pre[i]) - a;
  }
  add(pre[0]);
  for (int i = 1; i <= n; i++) {
    int ans = lower_bound(a + 1, a + 1 + len, a[pre[i]] - t) - a;
    if (a[ans] != a[pre[i]] - t) ans--;
    sum += i - ask(ans);
    add(pre[i]);
  }
  cout << sum << endl;
  return 0;
}
