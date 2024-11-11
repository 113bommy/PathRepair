#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i, c = 0, p, k;
  scanf("%d %d", &n, &m);
  for (i = 0; i < n; i++) {
    scanf("%d", &p);
    c = c + p;
    if (p >= k) k = p;
  }
  if ((c - k) <= m)
    printf("YES\n");
  else
    printf("NO\n");
}
