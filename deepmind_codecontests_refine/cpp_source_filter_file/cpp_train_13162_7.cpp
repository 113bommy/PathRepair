#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, c[100001], d, e = 0, i, n;
  scanf("%d%d", &n, &a);
  d = n - 1;
  for (i = 0; i < n; i++) {
    scanf("%d", &c[i]);
  }
  sort(c, c + a);
  for (i = 0; i < d; i++) {
    e += c[i];
  }
  if (e <= a) {
    printf("YES\n");
  } else
    printf("NO\n");
}
