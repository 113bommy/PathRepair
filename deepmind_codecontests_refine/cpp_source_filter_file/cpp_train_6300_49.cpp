#include <bits/stdc++.h>
using namespace std;
const int maxn = 120;
priority_queue<pair<double, int> > Q;
double p[maxn];
double p2[maxn];
int cnt[maxn];
double ans[100000];
int n;
double quickpow(double m, long long n) {
  double b = 1.0;
  while (n > 0) {
    if (n & 1) b = (b * m);
    n = n >> 1;
    m = (m * m);
  }
  return b;
}
double deal(int x) {
  return (1 - quickpow(p2[x], cnt[x] + 1)) / (1 - quickpow(p2[x], cnt[x]));
}
double Count(int x) { return (1 - quickpow(p2[x], cnt[x])); }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lf", &p[i]);
    p[i] /= 100;
    p2[i] = 1 - p[i];
  }
  for (int step = 1; step < 100000; step++) {
    double Max = deal(1);
    int tmp = 1;
    for (int i = 1; i <= n; i++) {
      if (cnt[i] == 0) {
        tmp = i;
        break;
      }
      if (deal(i) > Max) Max = deal(i), tmp = i;
    }
    cnt[tmp]++;
    double pro = 1;
    for (int i = 1; i <= n; i++) pro = pro * Count(i);
    ans[step] = pro;
  }
  double ans2 = 0;
  for (int i = 1; i < 100000; i++) ans2 += 1.0 * i * (ans[i] - ans[i - 1]);
  printf("%.12f\n", ans2);
}
