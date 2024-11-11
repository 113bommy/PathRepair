#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  int a[2003], b[2003], c[2003], d = 0, e = 0;
  for (int i = 0; i < t; i++) {
    scanf("%d", &a[i]);
    if (a[i] % 2 == 1)
      b[d++] = a[i];
    else
      c[e++] = a[i];
  }
  sort(b, b + d);
  sort(c, c + e);
  long long sum1 = 0, m;
  if (d - e >= 2) {
    m = d - e - 1;
    for (int i = 0; i < m; i++) sum1 += b[i];
    printf("%lld", sum1);
    return 0;
  } else if (e - d >= 2) {
    m = e - d - 1;
    for (int i = 0; i < m; i++) sum1 += c[i];
    printf("%lld", sum1);
    return 0;
  } else
    printf("0");
  return 0;
}
