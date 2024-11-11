#include <bits/stdc++.h>
using namespace std;
long long n, sum, first, b, k, ar[100000 + 5];
pair<long long, long long> p[100000 + 5];
int main() {
  long long i;
  scanf("%I64d %I64d", &n, &k);
  scanf("%I64d", &b);
  for (i = 0; i < n; i++) {
    scanf("%I64d", &ar[i]);
    p[i] = make_pair(ar[i], i);
  }
  sort(p, p + n - 1);
  reverse(p, p + n - 1);
  first = 2123123123;
  for (i = 0; i < k; i++) {
    sum += p[i].first;
    first = min(first, p[i].second);
  }
  if (sum <= b) {
    printf("%I64d\n", n);
    return 0;
  }
  for (i = 0; i < first; i++) {
    if (sum - p[k - 1].first + ar[i] > b) {
      printf("%I64d\n", i + 1);
      return 0;
    }
  }
  printf("%d\n", first);
}
