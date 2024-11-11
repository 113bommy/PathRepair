#include <bits/stdc++.h>
using namespace std;
map<long long, long long> ap[30];
long long cate, k, n, i, a[40], p[20];
long long S;
void back1(long long pos, long long sum, long long k1) {
  if (pos == n / 2 + 1) {
    ap[k1][sum]++;
    return;
  }
  for (int i = 0; i <= 2; i++) {
    if (i == 0)
      back1(pos + 1, sum, k1);
    else if (i == 1 && sum + a[pos] <= S)
      back1(pos + 1, sum + a[pos], k1);
    else if (i == 2 && a[pos] <= 18 && k1 < k && sum + p[a[pos]] <= S)
      back1(pos + 1, sum + p[a[pos]], k1 + 1);
  }
}
void back2(long long pos, long long sum, long long k1) {
  if (pos == n + 1) {
    for (int i = 0; i <= k - k1; i++)
      if (sum <= S && ap[i].count(S - sum)) cate = cate + ap[i][S - sum];
    return;
  }
  for (int i = 0; i <= 2; i++) {
    if (i == 0)
      back2(pos + 1, sum, k1);
    else if (i == 1 && sum + a[pos] <= S)
      back2(pos + 1, sum + a[pos], k1);
    else if (i == 2 && a[pos] <= 18 && k1 < k && sum + p[a[pos]] <= S)
      back2(pos + 1, sum + p[a[pos]], k1 + 1);
  }
}
int main() {
  scanf("%I64d %I64d %I64d", &n, &k, &S);
  for (i = 1; i <= n; i++) scanf("%I64d", &a[i]);
  sort(a + 1, a + n + 1);
  p[0] = 1;
  for (i = 1; i <= 18; i++) p[i] = p[i - 1] * i;
  back1(1, 0, 0);
  back2(n / 2 + 1, 0, 0);
  printf("%I64d", cate);
  return 0;
}
