#include <bits/stdc++.h>
using namespace std;
int n, t[100005], f, cnt;
long long a[100005], s;
queue<int> q[65];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    for (int j = 60; j >= 0; j--)
      if ((a[i] >> j) & 1) {
        q[j].push(i);
        break;
      }
  }
  for (int i = 1; i <= n; i++) {
    f = 0;
    for (int j = 0; j <= 60; j++)
      if (!(s & (1 << j)) && !q[j].empty()) {
        t[++cnt] = q[j].front();
        q[j].pop();
        f = 1;
        s ^= a[t[cnt]];
        break;
      }
  }
  if (!f || cnt != n) return puts("No"), 0;
  puts("Yes");
  for (int i = 1; i <= cnt; i++) printf("%lld ", a[t[i]]);
  return 0;
}
