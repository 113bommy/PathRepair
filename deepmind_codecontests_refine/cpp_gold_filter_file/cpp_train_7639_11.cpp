#include <bits/stdc++.h>
using namespace std;
const int maxx = 600010;
const double pi = acos(-1.0);
const double eps = 1e-15;
int t, n, m;
int total = 0, sum = 0, cnt = 0;
int nx[maxx];
long long b, d;
long long ans = 0;
long long val[maxx];
char c1[maxx], c2[maxx];
int main() {
  scanf("%lld%lld", &b, &d);
  scanf(" %s", c1);
  scanf("%s", c2);
  int l1 = strlen(c1), l2 = strlen(c2);
  for (int i = 0; i < l2; i++) {
    cnt = i;
    for (int j = 0; j < l1; j++)
      if (c1[j] == c2[cnt]) {
        cnt++;
        if (cnt == l2) val[i]++, cnt = 0;
      }
    nx[i] = cnt;
  }
  cnt = 0;
  for (int i = 1; i <= b; i++) {
    ans += val[cnt];
    cnt = nx[cnt];
  }
  ans /= d;
  printf("%lld", ans);
  return 0;
}
