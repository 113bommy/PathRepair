#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 111, inf = 1e9, mod = 1e9 + 7;
const long long linf = 1e18;
int a[N], n, le, re, odd, even, lo, ro;
vector<int> v;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  if (n == 1) {
    printf("%d", a[1]);
    return 0;
  }
  if (n % 2 == 1) {
    even = a[n / 2 + 1];
    lo = n / 2, ro = n / 2 + 2;
    le = n / 2 + 1, re = n / 2 + 1;
  } else {
    odd = min(a[n / 2], a[n / 2 + 1]);
    le = n / 2 + 1, re = n / 2;
    lo = n / 2, ro = n / 2 + 1;
  }
  for (int i = 1; i <= n - 2; ++i) {
    if ((n - i) % 2 == 0) {
      lo--, ro++;
      odd = max(odd, max(min(a[lo], a[lo + 1]), min(a[ro], a[ro - 1])));
      v.push_back(odd);
    } else {
      le--, re++;
      even = max(even, max(a[le], a[re]));
      v.push_back(even);
    }
  }
  for (auto j : v) printf("%d ", j);
  printf("%d %d", *max_element(a + 1, a + n + 1),
         *max_element(a + 1, a + n + 1));
  return 0;
}
