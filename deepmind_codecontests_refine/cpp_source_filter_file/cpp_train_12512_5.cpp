#include <bits/stdc++.h>
char s[200010];
int len, q;
int opt, l, r;
char x[5];
struct treey_array {
  int tree[100010];
  treey_array() {
    for (int i = 1; i <= 100000; ++i) tree[i] = 0;
  }
  void update(int x, int y, int n) {
    for (; x <= n; x += x & (-x)) tree[x] += y;
  }
  int query(int x) {
    int ans = 0;
    for (; x; x -= x & (-x)) ans += tree[x];
    return ans;
  }
} t[30];
int main() {
  scanf("%s%d", s + 1, &q);
  len = strlen(s + 1) - 1;
  for (int i = 1; i <= len; ++i) t[s[i] - 'a'].update(i, 1, len);
  for (int i = 1; i <= q; ++i) {
    scanf("%d", &opt);
    if (opt == 1) {
      scanf("%d%s", &l, x);
      t[s[l] - 'a'].update(l, -1, len);
      t[x[0] - 'a'].update(l, 1, len);
      s[l] = x[0];
    } else {
      scanf("%d%d", &l, &r);
      int ans = 0;
      for (int j = 0; j < 26; ++j) ans += !!(t[j].query(r) - t[j].query(l - 1));
      printf("%d\n", ans);
    }
  }
  return 0;
}
