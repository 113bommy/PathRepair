#include <bits/stdc++.h>
using namespace std;
int maxn = 0, a[50] = {0}, m, n, t = 0;
int main() {
  scanf("%d %d", &m, &n);
  while (m || n) {
    a[t++] = m % 10 + n % 10;
    maxn = max(m % 10, max(n % 10, maxn));
    m /= 10, n /= 10;
  }
  maxn++;
  for (int i = 0; i < t; i++)
    if (a[i] >= maxn) a[i + 1] = a[i] / maxn, a[i] %= maxn;
  if (a[t] < maxn && a[t] > 0)
    t++;
  else if (a[t] >= maxn)
    t += 2;
  printf("%d\n", t);
}
