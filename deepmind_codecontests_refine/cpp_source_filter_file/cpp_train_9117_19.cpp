#include <bits/stdc++.h>
using namespace std;
int a[255];
double f[2010];
double solve1(int p) {
  double sum = 0;
  for (int i = 1; i <= 250; i++) {
    if (a[i] >= 0 && a[i] <= p * 2)
      sum += log(1.0 / (p * 2 + 1));
    else
      return -1e20;
  }
  return sum;
}
double solve2(int p) {
  double sum = 0;
  for (int i = 1; i <= 250; i++) {
    sum += a[i] * log(p) - p - f[a[i]];
  }
  return sum;
}
int main() {
  for (int i = 1; i <= 2000; i++) f[i] = f[i - 1] + log(i);
  int t;
  scanf("%d", &t);
  while (t--) {
    for (int i = 1; i <= 250; i++) scanf("%d", &a[i]);
    double m1 = -1e20, ans;
    int pp;
    for (int p = 10; p <= 1000; p++) {
      ans = max(solve2(p), solve1(p));
      if (ans > m1) {
        ans = m1;
        pp = p;
      }
    }
    cout << pp << endl;
  }
  return 0;
}
