#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int a[N], b[N], d[N], n;
long long suma = 0, sumb = 0;
bool check() {
  long long cura = 0, curb = 0;
  for (int i = 1; i <= n / 2 + 1; ++i) cura += a[d[i]], curb += b[d[i]];
  return 2 * cura > suma && 2 * curb > sumb;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), suma += a[i];
  for (int i = 1; i <= n; ++i) scanf("%d", &b[i]), sumb += b[i];
  srand(time(0));
  for (int i = 1; i <= n; ++i) d[i] = i;
  printf("%d\n", n / 2 + 1);
  while (1) {
    random_shuffle(d + 1, d + n + 1);
    if (check()) {
      for (int i = 1; i <= n / 2 + 1; ++i) printf("%d ", i);
      puts("");
      return 0;
    }
  }
  return 0;
}
