#include <bits/stdc++.h>
using namespace std;
int N, T, mx;
char str[510000];
int a[510000];
int calc(int cur) {
  int last = 0, ans = 0;
  for (int i = 0; i < N; i++) {
    if (cur >= 0 && i > mx) {
      last = i;
      break;
    }
    a[i] = 1;
    if (cur < 0) a[i]++;
    if (str[i] == 'H')
      cur--;
    else if (str[i] == 'S')
      cur++;
    if (cur < 0) a[i]++;
    ans += a[i];
  }
  if (cur < 0) return 0x3f3f3f3f;
  int best = ans;
  for (int i = last - 1; i >= 0; i--) {
    if (i == last - 1)
      ans += 1 - a[i];
    else
      ans += 2 - a[i];
    if (best > ans) best = ans;
  }
  return best;
}
int main() {
  scanf("%d%d%s", &N, &T, &str);
  for (int i = 0; str[i]; i++)
    if (str[i] == 'H') mx = i;
  int high = N + 1, low = 0;
  while (high > low + 1) {
    int mid = (high + low) / 2;
    if (calc(mid) <= T)
      high = mid;
    else
      low = mid;
  }
  if (calc(low) <= T)
    printf("%d\n", low);
  else if (calc(high) <= T)
    printf("%d\n", high);
  else
    puts("-1");
  return 0;
}
