#include <bits/stdc++.h>
using namespace std;
struct name {
  int cnt, id, len;
} a[101];
bool cmp(name x, name y) {
  if (x.cnt == y.cnt) return x.id < y.id;
  return x.cnt < y.cnt;
}
int main() {
  int n, m, k, x;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= m; i++) {
    scanf("%d", &a[i].len);
    a[i].id = i;
  }
  for (int i = 1; i <= k; i++) {
    scanf("%d", &x);
    for (int i = 1; i <= m; i++)
      if (x % a[i].len == 0) a[i].cnt++;
  }
  sort(a + 1, a + m + 1, cmp);
  int ans = 1;
  for (int i = 2; i <= m; i++) {
    if (a[i].cnt == a[i - 1].cnt)
      ans++;
    else
      break;
  }
  printf("%d\n%d ", ans, a[1].id);
  for (int i = 2; i <= m; i++) {
    if (a[i].cnt == a[i - 1].cnt)
      printf("%d ", a[i].id);
    else
      break;
  }
}
