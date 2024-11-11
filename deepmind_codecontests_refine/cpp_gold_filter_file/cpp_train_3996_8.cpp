#include <bits/stdc++.h>
using namespace std;
const int Maxn = 100005;
int n;
long long a[Maxn];
int m;
int nil = 0;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%I64d", &a[i]);
  scanf("%d", &m);
  while (m--) {
    long long w, h;
    scanf("%I64d %I64d", &w, &h);
    w--;
    if (w < nil) w = nil;
    printf("%I64d\n", a[w]);
    long long res = a[w] + h;
    nil = upper_bound(a + nil, a + n, res) - 1 - a;
    a[nil] = res;
  }
  return 0;
}
