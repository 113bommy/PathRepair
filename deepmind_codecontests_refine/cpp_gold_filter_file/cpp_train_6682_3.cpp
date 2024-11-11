#include <bits/stdc++.h>
using namespace std;
long long a[2500], sz = 0;
void f(int x, int l, long long num) {
  if (x == l) {
    a[sz++] = num;
    return;
  }
  f(x + 1, l, num * 10 + 4);
  f(x + 1, l, num * 10 + 7);
}
int main() {
  int l, r;
  scanf("%d %d", &l, &r);
  for (int i = 1; i <= 10; ++i) f(0, i, 0);
  sort(a, a + sz);
  int k = lower_bound(a, a + sz, l) - a;
  long long ans = 0;
  for (long long i = l; i <= r;) {
    long long q = min((long long)r, a[k]);
    ans += (q - i + 1) * a[k] * 1ll;
    i = a[k++] + 1;
  }
  cout << ans << "\n";
}
