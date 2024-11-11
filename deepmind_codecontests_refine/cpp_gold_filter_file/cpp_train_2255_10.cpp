#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
long long a[maxn], k[maxn], s[maxn];
int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
    if (i) {
      s[i] = a[i] + s[i - 1];
    } else
      s[i] = a[i];
  }
  for (int i = 0; i < q; i++) scanf("%lld", &k[i]);
  long long rest = 0;
  for (int i = 0; i < q; i++) {
    long long low = 0, high = n, mid;
    while (low < high) {
      mid = (low + high) / 2;
      if (s[mid] == k[i] + rest) {
        low = mid + 1;
        break;
      }
      if (s[mid] < k[i] + rest)
        low = mid + 1;
      else
        high = mid;
    }
    rest = rest + k[i];
    if (n - low == 0) {
      low = 0;
      rest = 0;
    }
    printf("%lld\n", n - low);
  }
  return 0;
}
