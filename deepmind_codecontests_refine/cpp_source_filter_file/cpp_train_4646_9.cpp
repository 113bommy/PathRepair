#include <bits/stdc++.h>
using namespace std;
const int N = (2e5 + 10) * 3;
int n, l[N], r[N], num[N], size, val[N], cnt[N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &l[i], &r[i]);
    num[i] = l[i];
    num[i + n] = r[i];
    num[i + n + n] = l[i] - 1;
  }
  sort(num + 1, num + 1 + n * 2);
  size = unique(num + 1, num + 1 + n * 2) - num - 1;
  for (int i = 1; i <= n; i++) {
    l[i] = lower_bound(num + 1, num + 1 + size, l[i]) - num;
    r[i] = lower_bound(num + 1, num + 1 + size, r[i]) - num;
    val[l[i]]++;
    val[r[i] + 1]--;
  }
  for (int i = 1; i <= size; i++) {
    val[i] += val[i - 1];
  }
  for (int i = 1; i <= size; i++) {
    cnt[i] += cnt[i - 1] + (val[i] == 1);
  }
  for (int i = 1; i <= n; i++) {
    if (cnt[r[i]] - cnt[l[i] - 1] == 0) {
      printf("%d\n", i);
      return 0;
    }
  }
  puts("-1");
}
