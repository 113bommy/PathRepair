#include <bits/stdc++.h>
using namespace std;
long long resp, p[300010], t, fim[300010];
int n, m, a, b, h;
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &h);
    p[h] = i;
  }
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &a, &b);
    fim[max(p[a], p[b])] = max(fim[max(p[a], p[b])], min(p[a], p[b]));
  }
  for (int i = 0; i < n; i++) {
    if (fim[i]) {
      t = min(t + 1, i - fim[i]);
    } else {
      t++;
    }
    resp += t;
  }
  printf("%lld\n", resp);
  return 0;
}
