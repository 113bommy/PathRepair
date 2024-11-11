#include <bits/stdc++.h>
using namespace std;
char s[100010];
int main() {
  int n, k, a, b, p = 0, i;
  scanf("%d %d %d %d", &n, &k, &a, &b);
  bool flag = 1, c;
  if (a > b) {
    int tmp = min(k, a - b);
    for (i = 1; i <= tmp; i++) {
      a--;
      s[p++] = 'G';
    }
    c = 0;
  } else if (b > a) {
    int tmp = min(k, b - a);
    for (i = 1; i <= tmp; i++) {
      b--;
      s[p++] = 'B';
    }
    c = 1;
  } else {
    for (i = 1; i <= a; i++) s[p++] = ((i % 2 == 1) ? 'G' : 'B');
    a = b = 0;
  }
  while (a || b) {
    if (a == b) {
      if (c)
        for (i = 1; i <= a * 2; i++) s[p++] = ((i % 2 == 1) ? 'G' : 'B');
      else
        for (i = 1; i <= a * 2; i++) s[p++] = ((i % 2 == 1) ? 'B' : 'G');
      break;
    }
    if (c) {
      if (a == 0) {
        flag = 0;
        break;
      }
      a--;
      s[p++] = 'G';
      int tmp = min(k, b - a);
      for (i = 1; i <= tmp; i++) {
        b--;
        s[p++] = 'B';
      }
      c = 1;
    } else {
      if (b == 0) {
        flag = 0;
        break;
      }
      b--;
      s[p++] = 'B';
      int tmp = min(k, a - b);
      for (i = 1; i <= tmp; i++) {
        a--;
        s[p++] = 'G';
      }
      c = 0;
    }
  }
  if (!flag)
    printf("NO\n");
  else {
    s[p] = '\0';
    printf("%s", s);
  }
}
