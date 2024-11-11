#include <bits/stdc++.h>
int N, min1 = 1000000000, min2 = 1000000000, min3 = 1000000000, max1 = 0,
       max2 = 0, max3 = -1000000000, O1, O2;
bool check(int mid) {
  int upp1 = min1 + mid;
  int low1 = max1 - mid;
  int upp2 = min2 + mid;
  int low2 = max2 - mid;
  int upp3 = min3 + mid;
  int low3 = max3 - mid;
  if (low1 > upp1) return false;
  if (low2 > upp2) return false;
  if (std::max(low3, low1 - upp2) > std::min(upp3, upp1 - low2)) return false;
  for (int i = std::max(low1, 0); i <= upp1; i++) {
    int L = std::max(int(i == 0), std::max(low2, i - upp3));
    int R = std::max(upp2, i - low3);
    if (L <= R) {
      O1 = i;
      O2 = L;
      return true;
    }
  }
  return false;
}
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    static char in[500002];
    scanf("%s", in);
    int T1 = 0, T2 = 0;
    for (int j = 0; in[j]; j++)
      if (in[j] == 'B')
        T1++;
      else
        T2++;
    min1 = std::min(min1, T1);
    min2 = std::min(min2, T2);
    min3 = std::min(min3, T1 - T2);
    max1 = std::max(max1, T1);
    max2 = std::max(max2, T2);
    max3 = std::max(max3, T1 - T2);
  }
  int l = 0, r = 500000;
  while (l < r) {
    int m = l + r >> 1;
    if (check(m))
      r = m;
    else
      l = m + 1;
  }
  printf("%d\n", l);
  while (O1--) putchar('B');
  while (O2--) putchar('N');
  puts("");
  return 0;
}
