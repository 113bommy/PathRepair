#include <bits/stdc++.h>
using namespace std;
long long n, m, k, tot[1005][1005], rel[1005][1005];
struct node {
  long long x, y;
} s[1005];
struct node2 {
  long long r, x, y;
} cir[1005];
bool sur(int i, int j) {
  if (rel[i][j]) return rel[i][j] - 1;
  if ((s[i].x - cir[j].x) * (s[i].x - cir[j].x) +
          (s[i].y - cir[j].y) * (s[i].y - cir[j].y) <
      (cir[j].r * cir[j].r))
    rel[i][j] = 2;
  else
    rel[i][j] = 1;
  return rel[i][j] - 1;
}
int main() {
  long long a, b;
  scanf("%lld%lld%lld", &n, &m, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%lld%lld", &s[i].x, &s[i].y);
  }
  for (int i = 1; i <= m; i++)
    scanf("%lld%lld%lld", &cir[i].r, &cir[i].x, &cir[i].y);
  long long ans;
  for (int i = 1; i <= k; i++) {
    scanf("%lld%lld", &a, &b);
    if (tot[a][b]) {
      printf("%lld", tot[a][b]);
      continue;
    }
    ans = 0;
    for (int j = 1; j <= m; j++)
      if (sur(a, j) ^ sur(b, j)) ans++;
    tot[a][b] = tot[b][a] = ans;
    printf("%lld\n", ans);
  }
  return 0;
}
