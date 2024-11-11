#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const int maxn = 400050;
int a[maxn], b[maxn];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  int ans = 0;
  for (int p = 1; p <= 10000000; p <<= 1) {
    for (int i = 1; i <= n; i++) b[i] = a[i] & (p - 1);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
      if ((a[i] & p)) {
        sum++;
      }
    }
    if ((sum & 1) && ((n - 1) & 1)) ans ^= p;
    sort(b + 1, b + 1 + n);
    int pos = n;
    sum = 0;
    for (int i = 1; i <= n; i++) {
      pos = max(pos, i);
      for (; pos > i && (b[pos] + b[i]) >= p; pos--)
        ;
      sum ^= (n - pos);
    }
    if (sum & 1) ans ^= p;
  }
  printf("%d\n", ans);
}
