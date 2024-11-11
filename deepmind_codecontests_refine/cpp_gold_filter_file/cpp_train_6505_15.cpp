#include <bits/stdc++.h>
long long a[100005];
long long dup[100005];
int last;
int n, m;
int check(long long t) {
  int cur = last;
  long long temp;
  long long temp2;
  for (int i = 0; i < 100005; i++) dup[i] = a[i];
  for (int i = 0; i < m; i++) {
    temp = t;
    temp -= cur;
    while (temp >= 0) {
      temp2 = temp;
      temp -= dup[cur];
      dup[cur] -= temp2;
      if (dup[cur] <= 0) cur--;
      if (cur == 0) break;
    }
    if (cur == 0) break;
  }
  if (cur == 0) return 1;
  return 0;
}
long long bsearch(long long l, long long r) {
  long long m = (l + r) / 2;
  if (l >= r) return l;
  if (check(m))
    return bsearch(l, m);
  else
    return bsearch(m + 1, r);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", &a[i]);
    if (a[i]) last = i;
  }
  printf("%I64d", bsearch(0, 1000000000000000));
}
