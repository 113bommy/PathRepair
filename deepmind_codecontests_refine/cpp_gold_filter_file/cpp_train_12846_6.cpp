#include <bits/stdc++.h>
using namespace std;
const int mo = 1e9 + 7;
int pow(int a, int b, int c) {
  int ret = 1;
  for (; b; b >>= 1, a = 1LL * a * a % c)
    if (b & 1) ret = 1LL * ret * a % c;
  return ret;
}
bitset<1001> b[1005];
int n, m, a[1005][1005], bin[1000010], cnt;
int check(int v) {
  for (int i = (1); i <= (n); i++) b[i].reset();
  for (int i = (1); i <= (n); i++)
    for (int j = (1); j <= (m); j++)
      if (a[i][j] >= v) b[i].set(j);
  for (int i = (1); i <= (n); i++)
    for (int j = (i + 1); j <= (n); j++)
      if ((b[i] & b[j]).count() >= 2) return 1;
  return 0;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = (1); i <= (n); i++)
    for (int j = (1); j <= (m); j++)
      scanf("%d", &a[i][j]), bin[++cnt] = a[i][j];
  sort(bin + 1, bin + cnt + 1);
  cnt = unique(bin + 1, bin + cnt + 1) - bin - 1;
  int l = 1, r = cnt, mid;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (check(bin[mid]))
      l = mid + 1;
    else
      r = mid - 1;
  }
  printf("%d\n", bin[r]);
  return 0;
}
