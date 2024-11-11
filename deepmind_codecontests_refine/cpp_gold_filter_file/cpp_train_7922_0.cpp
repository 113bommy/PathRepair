#include <bits/stdc++.h>
using namespace std;
long long a, b, c, d, e, t, n, m, s, qw[100007] = {0}, zh[100007] = {0};
int main() {
  scanf("%I64d%I64d%I64d%I64d", &n, &m, &s, &t);
  s--;
  while (t % n) {
    if (s < m)
      s = (s + t % n) % n;
    else
      s = (s - t % n + n) % n;
    t--;
  }
  for (int i = 0; i <= n; i++) qw[i] = -1;
  zh[0] = s;
  qw[s] = 0;
  t /= n;
  for (int i = 1; i <= t; i++) {
    for (int j = 1; j <= n - 1; j++)
      if (s >= m)
        s = (s + j % n) % n;
      else
        s = (s - j % n + n) % n;
    if (qw[s] >= 0) {
      s = zh[(t - qw[s]) % (i - qw[s]) + qw[s]];
      break;
    } else
      qw[s] = i;
    zh[i] = s;
  }
  printf("%I64d\n", s + 1);
  return 0;
}
