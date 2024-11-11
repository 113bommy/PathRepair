#include <bits/stdc++.h>
using namespace std;
int a[120], n, k, p, v[120], mx = -1, mn = 2000000000;
int main(int argc, char *argv[]) {
  scanf("%d%d", &n, &k);
  p = n / k;
  do {
    memset(v, 0, sizeof(v));
  } while (0);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  int m;
  scanf("%d", &m);
  while (m--) {
    int sum = 0, tmp;
    for (int i = 0; i < p; i++) {
      scanf("%d", &tmp);
      tmp--;
      sum += a[tmp];
      v[tmp] = 1;
    }
    mx = max(mx, sum);
    mn = min(mn, sum);
  }
  int cnt = 0, lf[120];
  for (int i = 0; i < n; i++)
    if (v[i] == 0) lf[cnt++] = a[i];
  if (cnt <= n - p * k) {
    printf("%f %f\n", 1.0 * mn / p, 1.0 * mx / p);
    return 0;
  }
  sort(lf, lf + cnt);
  int s1 = 0, s2 = 0;
  for (int i = 0; i < p; i++) {
    s1 += lf[i];
    s2 += lf[cnt - 1 - i];
  }
  mx = max(mx, s2);
  mn = min(mn, s1);
  printf("%f %f\n", 1.0 * mn / p, 1.0 * mx / p);
  return EXIT_SUCCESS;
}
