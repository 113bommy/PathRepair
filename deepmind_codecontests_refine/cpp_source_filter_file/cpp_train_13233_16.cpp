#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
const int maxm = 2000000 + 10;
int n, a[maxn], ans[maxn], num[maxm], pos[maxm];
int main() {
  memset(num, 0, sizeof(num));
  scanf("%d", &n);
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    sum += a[i];
  }
  for (int i = 0; i < n; i++) {
    num[2 * a[i]]++;
    if (num[2 * a[i]] == 1) pos[2 * a[i]] = i;
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (sum - a[i] <= 1000000 && num[sum - a[i]]) {
      if (num[sum - a[i]] == 1 && pos[sum - a[i]] == i) continue;
      ans[cnt++] = i;
    }
  }
  printf("%d\n", cnt);
  for (int i = 0; i < cnt; i++)
    printf("%d%c", ans[i] + 1, i == cnt - 1 ? '\n' : ' ');
  return 0;
}
