#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
long long n, m, k, x, s[maxn][2], cnt;
int main() {
  scanf("%d %d %d", &n, &k, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    if (!cnt || s[cnt][0] != x) {
      s[++cnt][0] = x;
      s[cnt][1] = 1;
    } else
      s[cnt][1]++;
    if (s[cnt][1] == k) {
      s[cnt][1] = 0;
      cnt--;
    }
  }
  long long tot = 0;
  for (int i = 1; i <= cnt; i++) tot += s[i][1];
  int head = 1, tail = cnt;
  while (head < tail && s[head][0] == s[tail][0]) {
    if ((s[head][1] + s[head][0]) % k == 0) {
      head++;
      tail--;
    } else {
      s[head][1] = (s[head][1] + s[tail][1]) % k;
      s[tail][1] = 0;
      break;
    }
  }
  long long ans = 0;
  if (head < tail) {
    for (int i = head; i <= tail; i++) ans += s[i][1];
    ans = ans * (m - 1);
    ans += tot;
  } else if (head == tail) {
    if ((s[head][1] * m) % k == 0)
      ans = 0;
    else {
      ans = tot + s[head][1] * (m - 1);
      ans -= s[head][1] * m - s[head][1] * m % k;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
