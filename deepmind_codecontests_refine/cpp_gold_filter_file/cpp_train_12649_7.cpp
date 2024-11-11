#include <bits/stdc++.h>
using namespace std;
int a[200005], n, x, m;
int main() {
  scanf("%d", &n);
  x = n / 2;
  m = 1000000000;
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  sort(a, a + n);
  for (int i = x; i < n; i++) m = min(m, a[i] - a[i - x]);
  printf("%d", m);
}
