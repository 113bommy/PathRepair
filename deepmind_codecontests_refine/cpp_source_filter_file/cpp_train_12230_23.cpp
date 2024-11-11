#include <bits/stdc++.h>
int n, c;
int last_left[1000010], first_right[1000010], last_right[1000010];
char dst[10000000];
char *ptr = dst;
int build_tree(int id, int last_mand, int first_bad) {
  if (last_mand < last_right[id]) last_mand = last_right[id];
  if (last_mand >= first_bad) return 0;
  int last_used = id;
  if (last_left[id])
    last_used = build_tree(id + 1, last_left[id],
                           first_right[id] ? first_right[id] : first_bad);
  if (!last_used) return 0;
  ptr += sprintf(ptr, "%d ", id);
  if (last_mand >= last_used + 1)
    return build_tree(last_used + 1, last_mand, first_bad);
  else
    return id;
}
int main() {
  scanf("%d%d", &n, &c);
  int a, b;
  char s[10];
  for (int i = 0; i < c; i++) {
    scanf("%d%d%s", &a, &b, s);
    if (a >= b) {
      puts("IMPOSSIBLE");
      return 0;
    }
    if (s[0] == 'L') {
      if (!last_left[a] || last_left[a] < b) last_left[a] = b;
    } else {
      if (!last_right[a] || last_right[a] < b) last_right[a] = b;
      if (!first_right[a] || first_right[a] > b) first_right[a] = b;
    }
    if (first_right[a] && (last_left[a] >= first_right[a])) {
      puts("IMPOSSIBLE");
      return 0;
    }
  }
  if (build_tree(1, n, n + 1))
    puts(dst);
  else
    puts("IMPOSSIBLE");
  return 0;
}
