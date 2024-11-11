#include <bits/stdc++.h>
using namespace std;
int n, a, b, c, d;
char s[1000011];
int prenum[1000011];
bool work(int id0, int id1, int b, int c) {
  if (b + c != 1ll * id0 * id1) return 0;
  s[id0 + id1 + 1] = '\0';
  for (int i = 1, to = id0 + id1; i <= to; i++) {
    if (c < id0) {
      b -= id1;
      id0--;
      s[i] = '0';
    } else {
      c -= id0;
      id1--;
      s[i] = '1';
    }
    if (c < 0 || b < 0) return 0;
  }
  puts(s + 1);
  return 1;
}
int main() {
  for (int i = 0; i <= 50000; i++) prenum[i] = 1ll * i * (i - 1) / 2;
  scanf("%d%d%d%d", &a, &b, &c, &d);
  if (a == 0 && b == 0 && c == 0 && d == 0) {
    puts("1");
    return 0;
  }
  int id0 = -1, id1 = -1;
  for (int i = 0; i <= 50000; i++)
    if (prenum[i] == a) {
      id0 = i;
      break;
    }
  for (int i = 0; i <= 50000; i++)
    if (prenum[i] == d) {
      id1 = i;
      break;
    }
  if (id0 == -1 || id1 == -1) {
    puts("Impossible");
    return 0;
  }
  if (a && d) {
    if (work(id0, id1, b, c))
      ;
    else
      puts("Impossible");
  } else {
    if (!a && !d) {
      bool flag = 0;
      for (int i = 0; i < 2 && !flag; i++)
        for (int j = 0; j < 2 && !flag; j++)
          if (work(i, j, b, c)) flag = 1;
      if (!flag) puts("Impossible");
    } else if (!a) {
      bool flag = 0;
      for (int i = 0; i < 2 && !flag; i++)
        if (work(i, id1, b, c)) flag = 1;
      if (!flag) puts("Impossible");
    } else {
      bool flag = 0;
      for (int i = 0; i < 2 && !flag; i++)
        if (work(id0, i, b, c)) flag = 1;
      if (!flag) puts("Impossible");
    }
  }
  return 0;
}
