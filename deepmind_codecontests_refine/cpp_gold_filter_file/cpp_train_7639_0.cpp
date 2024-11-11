#include <bits/stdc++.h>
using namespace std;
struct node {
  int c, s;
  node() {}
  node(int a, int b) : c(a), s(b) {}
} a[10010];
char s[110], t[110];
int main() {
  int b, d;
  scanf("%d%d", &b, &d);
  scanf("%s%s", s, t);
  int n = strlen(s), len = strlen(t);
  for (int i = 0; i < len; i++) {
    node cur = node(0, i);
    for (int j = 0; j < n; j++) {
      if (s[j] == t[cur.s]) {
        cur.s++;
        if (cur.s == len) {
          cur.c++;
          cur.s = 0;
        }
      }
    }
    a[i] = cur;
  }
  int ans = 0, cur = 0;
  for (int i = 0; i < b; i++) {
    ans += a[cur].c;
    cur = a[cur].s;
  }
  printf("%d\n", ans / d);
  return 0;
}
