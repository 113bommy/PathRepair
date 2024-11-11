#include <bits/stdc++.h>
using namespace std;
const int N = 24;
int id, pr[N], sum;
int query(int x) {
  int res = 0;
  for (int i = 0; i < (1 << id); i++) {
    int num = 0, s = 1;
    for (int j = 0; j < id; j++)
      if (i >> j & 1) {
        num++;
        s *= pr[j + 1];
      }
    if (num & 1)
      res -= x / s;
    else
      res += x / s;
  }
  return res;
}
int main() {
  int T, x, p, k;
  scanf("%d", &T);
  while (T--) {
    id = 0;
    scanf("%d%d%d", &x, &p, &k);
    if (p == 1) {
      printf("%d\n", x + k);
      continue;
    }
    int temp = p;
    for (int i = 2; i * i <= temp; i++) {
      if (temp % i == 0) pr[++id] = i;
      while (temp % i == 0) temp /= i;
    }
    if (temp > 1) pr[++id] = temp;
    sum = query(x);
    int l = x, r = 2e7, ans = 2e9;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (query(mid) - sum >= k) {
        r = mid - 1;
        ans = min(mid, ans);
      } else
        l = mid + 1;
    }
    printf("%d\n", ans);
  }
  return 0;
}
