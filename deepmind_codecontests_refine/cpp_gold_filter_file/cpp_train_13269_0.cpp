#include <bits/stdc++.h>
using namespace std;
int n, ans[100010];
int cnt[100010], a[100010];
int main() {
  int last = -1;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), cnt[a[i]]++;
  for (int i = 2; i <= 100000; i++)
    if (cnt[i] > cnt[i - 1]) {
      puts("-1");
      return 0;
    }
  printf("%d\n", cnt[1]);
  for (int i = 1; i <= n; i++) printf("%d ", ++ans[a[i]]);
  return 0;
}
