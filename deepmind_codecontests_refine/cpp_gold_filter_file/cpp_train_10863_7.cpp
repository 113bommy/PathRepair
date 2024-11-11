#include <bits/stdc++.h>
using namespace std;
char s1[200005], s2[200005];
int n;
double sum1[26], sum2[26];
int main() {
  int i;
  scanf("%d", &n);
  scanf("%s%s", s1 + 1, s2 + 1);
  double tot = 0, ans = 0;
  for (i = 1; i <= n; i++) {
    int u1 = s1[i] - 'A';
    int u2 = s2[i] - 'A';
    ans += sum1[u2] * (n - i + 1);
    ans += sum2[u1] * (n - i + 1);
    sum1[u1] += i;
    sum2[u2] += i;
    if (u1 == u2) {
      ans += 1LL * i * (n - i + 1);
    }
  }
  tot = 1LL * n * (n + 1) * (2 * n + 1) / 6;
  printf("%.10lf\n", ans / tot);
  return 0;
}
