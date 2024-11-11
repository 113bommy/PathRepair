#include <bits/stdc++.h>
using namespace std;
int n, k;
char s[10][10];
int a[10], num[10];
void rearg(int id) {
  int ret = 0;
  for (int i = 0; i < k; i++) ret = ret * 10 + (s[id][a[i]] - '0');
  num[id] = ret;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%s", s[i]);
  for (int i = 0; i < n; i++) a[i] = i;
  int ans = 1 << 28;
  do {
    for (int i = 0; i < n; i++) rearg(i);
    int mi = 1 << 28, mx = -1 << 28;
    for (int i = 0; i < n; i++) {
      mi = min(mi, num[i]);
      mx = max(mx, num[i]);
    }
    ans = min(mx - mi, ans);
  } while (next_permutation(a, a + k));
  printf("%d\n", ans);
  return 0;
}
