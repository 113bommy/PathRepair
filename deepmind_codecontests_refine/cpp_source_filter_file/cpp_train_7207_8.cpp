#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
int n, res[maxn + 5], d1[maxn + 5], d2[maxn + 5], mp[maxn + 5];
int last1, last2, now1, now2;
int main() {
  scanf("%d %d %d", &n, &last1, &last2);
  for (int i = 1; i < n; ++i) {
    printf("+ %d\n", i);
    fflush(stdout);
    scanf("%d %d", &now1, &now2);
    d1[i] = now1 - last1, d2[i] = now2 - last2;
    if (d1[i] > 0)
      for (int x = 2; x <= n; ++x)
        if (x * (x - 1) / 2 == d1[i]) {
          mp[i] = x;
          break;
        }
    last1 = now1, last2 = now2;
  }
  printf("+ 1\n");
  fflush(stdout);
  scanf("%d %d", &now1, &now2);
  int f1 = now1 - last1, f2 = now2 - last2;
  for (int i = 0; i <= n; ++i) {
    if (i * (i + 1) / 2 == f1) {
      res[1] = i;
      break;
    }
  }
  int delta = f2 - d2[1] - 1;
  if (mp[2] >= 2)
    res[2] = mp[2], res[3] = delta - res[2];
  else if (mp[3] >= 2)
    res[3] = mp[3], res[2] = delta - res[3];
  else if (delta == 0)
    res[3] = res[2] = 0;
  else if (delta == 2)
    res[3] = res[2] = 1;
  else if (d2[2] > 0)
    res[2] = 0, res[3] = 1;
  else
    res[2] = 1, res[3] = 0;
  for (int i = 3; i <= n - 2; ++i) {
    if (mp[i + 1] >= 2) {
      res[i + 1] = res[i + 1];
      continue;
    }
    if ((res[i - 2] + 1) * (res[i - 1] + 1) == d2[i])
      res[i + 1] = 0;
    else
      res[i + 1] = 1;
  }
  res[n] = (d2[n - 1] - (res[n - 3] + 1) * (res[n - 2] + 1)) / (res[n - 2] + 1);
  printf("!");
  for (int i = 1; i <= n; ++i) printf(" %d", res[i]);
  puts(""), fflush(stdout);
  return 0;
}
