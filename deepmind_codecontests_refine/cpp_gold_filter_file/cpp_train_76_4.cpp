#include <bits/stdc++.h>
int arr[1000001];
std::set<int> entry;
int main() {
  int n, m, k, in, price, unavail = 1, max_unavail = 0;
  long long res = LLONG_MAX;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < m; i += 1) {
    scanf("%d", &in);
    arr[in] = 1;
    if (!in) {
      printf("-1");
      return 0;
    } else if (arr[in - 1])
      unavail += 1;
    else {
      max_unavail = std::max(max_unavail, unavail);
      unavail = 1;
      entry.insert(in - 1);
    }
  }
  max_unavail = std::max(max_unavail, unavail);
  if (!m) max_unavail = 0;
  for (int i = 1; i <= k; i += 1) {
    int ptr, count;
    scanf("%d", &in);
    if (i > max_unavail) {
      ptr = count = 0;
      while (ptr < n)
        if (arr[ptr]) {
          std::set<int>::iterator it = entry.lower_bound(ptr);
          ptr = *(--it);
        } else
          count += 1, ptr += i;
      res = std::min(res, (long long int)in * count);
    }
  }
  if (res == LLONG_MAX) res = -1;
  printf("%lld", res);
  return 0;
}
