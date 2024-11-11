#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, a, b, pa, push_back, max_, i;
  scanf("%lld", &n);
  scanf("%lld", &m);
  scanf("%lld", &pa);
  scanf("%lld", &push_back);
  max_ = push_back + (pa - 1);
  for (i = 0; i < m - 1; i++) {
    scanf("%lld", &a);
    scanf("%lld", &b);
    if (abs(push_back - b) > abs(a - pa)) {
      printf("IMPOSSIBLE");
      return 0;
    }
    long long ans = (a - pa + push_back - b) / 2;
    max_ = max(max_, ans);
    pa = a;
    push_back = b;
  }
  max_ = max(max_, push_back + n - pa);
  cout << max_;
  return 0;
}
