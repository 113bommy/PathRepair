#include <bits/stdc++.h>
using namespace std;
long long n, d, i, j, mx, lst, f;
pair<long long, long long> v[100005];
int main() {
  scanf("%I64d%I64d", &n, &d);
  for (i = 1; i <= n; i++) scanf("%I64d%I64d", &v[i].first, &v[i].second);
  sort(v + 1, v + n + 1);
  for (i = 1; i <= n; i++) {
    if (j < i) {
      f += v[i].second;
      j = i + 1;
    }
    while (j <= n && v[j].first - v[i].first < d) {
      f += v[j].second;
      j++;
    }
    if (f > mx) mx = f;
    f -= v[i].second;
  }
  printf("%I64d", mx);
  return 0;
}
