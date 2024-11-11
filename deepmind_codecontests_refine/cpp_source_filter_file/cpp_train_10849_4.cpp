#include <bits/stdc++.h>
using namespace std;
inline void up(int &a, const int &b) {
  if (a < b) a = b;
}
const int maxn = 24;
const int mask = 1 << 20;
int n, al;
long long val[maxn], sum[mask];
int num[mask];
int ok[mask], ans[mask];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &val[i]);
    if (val[i] == 0) i--, n--;
  }
  al = (1 << n) - 1;
  for (int s = 1; s <= al; s++) {
    for (int i = 1; i <= n; i++)
      if (s >> (i - 1) & 1) {
        sum[s] = sum[s ^ 1 << (i - 1)] + val[i];
        num[s] = num[s ^ 1 << (i - 1)] + 1;
        break;
      }
  }
  for (int s = 1; s <= al; s++) {
    int m = num[s] - 1;
    if ((sum[s] + m) & 1) continue;
    for (int j = (s - 1) & s; j; j = (j - 1) & s) {
      int x = j, y = s ^ j;
      long long dec = abs(sum[x] - sum[y]);
      if (dec % 2 == (long long)m % 2 && dec <= (long long)m) {
        ok[s] = 1;
        break;
      }
    }
  }
  for (int s = 1; s <= al; s++)
    if (ok[s] && !ans[s]) {
      ans[s] = 1;
      int oth = al ^ s;
      for (int j = oth; j; j = (j - 1) & s) up(ans[s | j], ans[j] + 1);
    }
  int ret = 0;
  for (int s = 1; s <= al; s++) up(ret, ans[s]);
  printf("%d\n", n - ret);
  return 0;
}
