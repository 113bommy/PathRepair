#include <bits/stdc++.h>
const int maxn = 100003;
struct Seg {
  int l, r, s;
} seg[maxn];
char str[maxn];
bool match(char a, char b) {
  return (a == '(' && b == ')') || (a == '[' && b == ']');
}
int main() {
  int i, j, n = 0, len;
  scanf("%s", str);
  len = strlen(str);
  for (i = 0; i < len - 1; i++) {
    if (match(str[i], str[i + 1])) {
      seg[n].l = i;
      seg[n].r = i + 1;
      seg[n].s = str[i] == '[';
      n++;
    }
  }
  bool flag = true;
  while (n && flag) {
    flag = false;
    for (i = 0; i < n; i++) {
      while (seg[i].l > 0 && seg[i].r < len - 1 &&
             match(str[seg[i].l - 1], str[seg[i].r + 1])) {
        seg[i].l--;
        seg[i].r++;
        seg[i].s += str[seg[i].l] == '[';
        flag = true;
      }
    }
    for (i = 1, j = 0; i < n; i++) {
      if (seg[i].l = seg[j].r + 1) {
        seg[j].r = seg[i].r;
        seg[j].s += seg[i].s;
        flag = true;
      } else {
        seg[++j] = seg[i];
      }
    }
    n = j + 1;
  }
  int mm = 0, l, r;
  for (i = 0; i < n; i++) {
    if (mm < seg[i].s) {
      mm = seg[i].s;
      l = seg[i].l;
      r = seg[i].r;
    }
  }
  printf("%d\n", mm);
  if (mm) {
    for (i = l; i <= r; i++) {
      printf("%c", str[i]);
    }
    printf("\n");
  }
  return 0;
}
