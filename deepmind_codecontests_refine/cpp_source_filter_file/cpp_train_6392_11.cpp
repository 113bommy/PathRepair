#include <bits/stdc++.h>
using namespace std;
long long p[100002], pr[100002];
int main() {
  int m, i;
  double r, dist = 0, sq, d = 0, mm;
  p[1] = 2;
  for (i = 2; i <= 100000; i++) p[i] = p[i - 1] + 2;
  for (i = 1; i <= 100000; i++) pr[i] = pr[i - 1] + p[i];
  cin >> m >> r;
  mm = m;
  sq = sqrt(2 * r * r);
  for (i = 1; i <= m; i++) {
    dist = 2 * r;
    if (i > 1) dist += sq + 2 * r;
    if (i < m) dist += sq + 2 * r;
    if (i > 2) dist += (i - 2) * 2 * sq + pr[i - 2];
    if (i < m - 1) dist += (m - i - 1) * 2 * sq + pr[m - i - 1];
    d += dist / mm;
  }
  printf("%.10f", d / mm);
  return 0;
}
