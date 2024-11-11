#include <bits/stdc++.h>
using namespace std;
int a[1000010];
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  if (m >= n) {
    printf("%I64d", (a[n] - a[1]) * 2ll);
    return 0;
  }
  int mid_pos = (n % 2 == 0 ? n / 2 : n / 2 + 1);
  int i = 1;
  long long total = 0;
  while (i + m <= mid_pos) {
    total += (a[mid_pos] - a[i]) * 2ll;
    i += m;
  }
  total += (a[mid_pos] - a[i]) * 2ll;
  i = n;
  while (i - m >= mid_pos) {
    total += (a[i] - a[mid_pos]) * 2ll;
    i -= m;
  }
  total += (a[i] - a[mid_pos]) * 2ll;
  printf("%I64d", total);
  return 0;
}
