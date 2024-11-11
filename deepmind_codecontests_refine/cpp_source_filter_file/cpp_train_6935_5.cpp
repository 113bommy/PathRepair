#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
const int mod = 12 * 3600;
int main() {
  int h, m, s, t1, t2, k, l;
  scanf("%d%d%d%d%d", &h, &m, &s, &t1, &t2);
  if (h == 12) h = 0;
  if (t2 == 12) t2 = 0;
  if (t1 == 12) t1 = 0;
  int a[] = {h * 3600 + m * 60 + s, m * 720 + 12 * s, s * 720};
  sort(a, a + 3);
  t1 *= 3600, t2 *= 3600;
  int itr = 0;
  if (t1 > t2) swap(t1, t2);
  if ((t1 < a[0] && t2 < a[0]) || (t1 < a[0] && t2 > a[0]) || (t1 > a[2])) {
    printf("YES");
    return 0;
  }
  for (int i = 0; i < 2; i++) {
    if (a[i] < t1 && t2 < a[i + 1]) {
      printf("YES");
      return 0;
    }
  }
  printf("NO");
}
