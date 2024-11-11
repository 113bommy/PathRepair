#include <bits/stdc++.h>
using namespace std;
long long a[1005][1005];
const int maxn = 1e6 + 5;
long long check[maxn][2];
priority_queue<long long> con[2];
int main(int argc, const char* argv[]) {
  long long n, m, k, p;
  scanf("%lld%lld%lld%lld", &n, &m, &k, &p);
  memset(a, 0, sizeof(a));
  memset(check, 0, sizeof(check));
  for (int i = 1; i <= n; i++) {
    long long in = 0;
    for (int j = 1; j <= m; j++) {
      scanf("%lld", &a[i][j]);
      in += a[i][j];
    }
    con[1].push(in);
  }
  for (int j = 1; j <= m; j++) {
    long long in = 0;
    for (int i = 1; i <= n; i++) {
      in += a[i][j];
    }
    con[0].push(in);
  }
  long long ans = -1e14;
  for (int flag = 0; flag < 2; flag++) {
    for (int j = 1; j <= k; j++) {
      long long nx = con[flag].top();
      con[flag].pop();
      check[j][flag] = check[j - 1][flag] + nx;
      if (flag)
        nx -= m * p;
      else
        nx -= n * p;
      con[flag].push(nx);
    }
  }
  for (long long i = 0; i <= k; i++) {
    ans = max(ans, check[i][0] + check[k - i][1] - i * (k - i) * p);
  }
  printf("%lld", ans);
  return 0;
}
