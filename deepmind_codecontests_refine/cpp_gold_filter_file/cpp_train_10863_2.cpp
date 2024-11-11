#include <bits/stdc++.h>
char s[2][200001];
long long ac[2][256] = {{0}, {0}};
int n;
int main() {
  scanf("%d%s%s", &n, s[0], s[1]);
  double t = n * (n + 1LL) * (2LL * n + 1) / 6, ans = 0;
  for (int i = 0; i < n; ++i)
    ac[0][s[0][i]] += i + 1,
        ans += (ac[0][s[1][i]] + ac[1][s[0][i]]) * (n - i) / t,
        ac[1][s[1][i]] += i + 1;
  printf("%.9lf\n", ans);
}
