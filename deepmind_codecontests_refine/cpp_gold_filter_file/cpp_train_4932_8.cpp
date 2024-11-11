#include <bits/stdc++.h>
using namespace std;
int n, p;
int a[100];
long double ans = 0.0;
long long num[100];
long long d[3000][52];
long double calc(long long num, int x) {
  long double res = num;
  int y = n - x;
  int z1, z2 = n;
  if (x > y) {
    z1 = x + 1;
    x = 1;
  } else {
    z1 = y + 1;
    y = 1;
  }
  vector<int> p;
  p.assign(100, 0);
  for (int i = 2; i <= x; i++) {
    int t = i;
    for (int j = 2; j * j <= t; j++) {
      while (t % j == 0) {
        p[j]++;
        t /= j;
      }
    }
    if (t) p[t]++;
  }
  for (int i = 2; i <= y; i++) {
    int t = i;
    for (int j = 2; j * j <= t; j++) {
      while (t % j == 0) {
        p[j]++;
        t /= j;
      }
    }
    if (t) p[t]++;
  }
  for (int i = z1; i <= z2; i++) {
    int t = i;
    for (int j = 2; j * j <= t; j++) {
      while (t % j == 0) {
        p[j]--;
        t /= j;
      }
    }
    if (t) p[t]--;
  }
  for (int i = 2; i <= 50; i++) {
    if (p[i] > 0) {
      for (int j = 1; j <= p[i]; j++) res *= i;
    }
    if (p[i] < 0) {
      for (int j = 1; j <= -p[i]; j++) res /= i;
    }
  }
  return res;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  scanf("%d", &p);
  d[0][0] = true;
  for (int i = 1; i <= n; i++) {
    for (int j = p; j >= a[i]; j--)
      for (int k = i; k >= 1; k--) {
        d[j][k] += d[j - a[i]][k - 1];
      }
  }
  for (int i = 1; i <= p; i++)
    for (int k = 1; k <= n; k++) num[k] += d[i][k];
  for (int i = 1; i <= n; i++) {
    if (num[i]) ans += calc(num[i], i);
  }
  printf("%.12lf", ans);
  return 0;
}
