#include <bits/stdc++.h>
const int maxn = int(3e5) + 7;
long long a[2][maxn], sum[maxn], buf[2][maxn], tmp_ans, ans;
int n;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < 2; i++)
    for (int j = 1; j <= n; j++) scanf("%lld", a[i] + j);
  for (int i = n; i >= 1; i--) sum[i] = sum[i + 1] + (a[0][i] + a[1][i]) * 2;
  for (int i = 1, j = n * 2; i <= n; i++, j--) {
    buf[0][i] = a[0][i] * i;
    buf[1][i] = a[1][i] * j;
    tmp_ans += buf[0][i] + buf[1][i];
  }
  ans = std::max(tmp_ans, ans);
  for (int i = 3, pre = 1, cnt = 1; i <= n; i += 2, pre += 2, cnt++) {
    tmp_ans -= buf[0][pre] + buf[1][pre] + buf[1][pre + 1] + buf[0][pre + 1];
    long long tmp = (pre / 2) * 4 + 1;
    buf[0][pre] = a[0][pre] * tmp;
    buf[1][pre] = a[1][pre] * (tmp + 1);
    buf[1][pre + 1] = a[1][pre + 1] * (tmp + 2);
    buf[0][pre + 1] = a[0][pre + 1] * (tmp + 3);
    tmp_ans += buf[0][pre] + buf[1][pre] + buf[1][pre + 1] + buf[0][pre + 1];
    ans = std::max(ans, tmp_ans + sum[i] * cnt);
  }
  buf[0][1] = a[0][1];
  buf[1][1] = a[1][1] << 1;
  tmp_ans = buf[0][1] + buf[1][1];
  for (int i = 2, p = n * 2, q = 3; i <= n; i++, p--, q++) {
    buf[0][i] = a[0][i] * p;
    buf[1][i] = a[1][i] * q;
    tmp_ans += buf[0][i] + buf[1][i];
  }
  ans = std::max(ans, tmp_ans);
  for (int i = 4, pre = 2, cnt = 1; i <= n; i += 2, pre += 2, cnt++) {
    tmp_ans -= buf[0][pre] + buf[1][pre] + buf[1][pre + 1] + buf[0][pre + 1];
    long long tmp = pre * 2 - 1;
    buf[1][pre] = a[1][pre] * tmp;
    buf[0][pre] = a[0][pre] * (tmp + 1);
    buf[0][pre + 1] = a[0][pre + 1] * (tmp + 2);
    buf[1][pre + 1] = a[1][pre + 1] * (tmp + 3);
    tmp_ans += buf[0][pre] + buf[1][pre] + buf[1][pre + 1] + buf[0][pre + 1];
    ans = std::max(ans, tmp_ans + sum[i] * cnt);
  }
  printf("%lld\n", ans - (sum[1] >> 1));
  return 0;
}
