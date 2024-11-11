#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const int inf = 0x3f3f3f3f;
const long long linf = 8e18 + 9e17;
const int mod = 1e9 + 7;
const double e = exp(1.0);
const double pi = acos(-1);
char s1[maxn], s2[maxn];
int sum[2][maxn] = {0};
int main() {
  int n;
  long long sumx0 = 0, sumt0 = 0, sumx1 = 0, sumt1 = 0, cnt0 = 0, cnt1 = 0;
  scanf("%d%s%s", &n, s1 + 1, s2 + 1);
  for (int i = 1; i <= n; i++) {
    if (s1[i] == '0')
      sumt0++;
    else
      sumt1++;
    if (s2[i] == '0') {
      if (s1[i] == '0')
        sumx1++;
      else
        sumx0++;
    }
    if (s1[i] == '0' && s2[i] == '1') cnt0++;
    if (s1[i] == '1' && s2[i] == '0') cnt1++;
  }
  printf("%lld\n", sumx1 * sumt1 + sumx0 * sumt0 - cnt0 * cnt1);
  return 0;
}
