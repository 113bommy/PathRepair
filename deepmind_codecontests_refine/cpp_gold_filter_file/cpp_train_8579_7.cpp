#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a[111111];
long long flag[111111];
int ctrl;
long long num[111111], s[111111];
int find(long long t) {
  int rank = int(lower_bound(s, s + m, t) - s);
  if (flag[rank] == 0)
    return a[rank];
  else
    return find((t - s[rank - 1] - 1) % a[rank] + 1);
}
int main() {
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf("%d%I64d", &ctrl, &a[i]);
    if (ctrl == 2) scanf("%I64d", &flag[i]);
  }
  for (int i = 0; i < m; i++) {
    if (flag[i] == 0)
      num[i] = 1;
    else
      num[i] = flag[i] * a[i];
  }
  s[0] = num[0];
  for (int i = 1; i < m; i++) s[i] = s[i - 1] + num[i];
  scanf("%d", &n);
  long long t;
  for (int i = 0; i < n; i++) {
    scanf("%I64d", &t);
    printf("%d ", find(t));
  }
  return 0;
}
