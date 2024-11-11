#include <bits/stdc++.h>
using namespace std;
int isp[1000010], p[1000010], cnt[1000010], pcnt = 0;
void euler() {
  for (int i = 2; i <= 1000000; ++i) {
    if (!isp[i]) p[++pcnt] = i;
    for (int j = 1; j <= pcnt && p[j] * i <= 1000000; ++j) {
      isp[i * p[j]] = 1;
      if (i % p[j] == 0) break;
    }
  }
}
int solve(int n) {
  int sqrtn = sqrt(n);
  return cnt[n] - cnt[sqrtn] + 1;
}
int main() {
  int T;
  cin >> T;
  euler();
  for (int i = 1; i <= 1000000; ++i) {
    cnt[i] = cnt[i - 1] + (isp[i] != 1);
  }
  while (T--) {
    int n;
    scanf("%d", &n);
    printf("%d\n", solve(n));
  }
}
