#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000001;
int a[MAXN], ans[MAXN], num, n, cnt;
bool mark[MAXN];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a + i), mark[a[i]] = true;
  for (int i = 0; i < n; i++)
    if (!mark[MAXN - a[i]]) ans[num++] = MAXN - a[i], cnt++;
  cnt = (n - cnt) / 2;
  for (int i = 1; cnt > 0 && i < MAXN; i++)
    if (!mark[i] && !mark[MAXN - i])
      ans[num++] = i, ans[num++] = MAXN - i, cnt--;
  printf("%d\n", num);
  for (int i = 0; i < num; i++) printf("%d ", ans[i]);
  return 0;
}
