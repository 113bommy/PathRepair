#include <bits/stdc++.h>
using namespace std;
int tp[205], x, y, p;
map<int, int> from;
int power(int x, int y) {
  int s = 1;
  for (; y; y /= 2, x = 1ll * x * x % p)
    if (y & 1) s = 1ll * s * x % p;
  return s;
}
int main() {
  srand(time(NULL));
  scanf("%d%d%d", &x, &y, &p);
  for (int i = (1); i <= (int)2000; i++) {
    int val = y;
    for (int j = (1); j <= (int)100; j++) {
      int type = rand() % 3 + 1, old = val;
      if (type == 1) val = (val + 1) % p;
      if (type == 2) val = (val + p - 1) % p;
      if (type == 3) val = power(val, p - 2);
      if (from.find(val) == from.end()) from[val] = old;
    }
  }
  for (int i = (1); i <= (int)2000; i++) {
    int val = x;
    for (int j = (1); j <= (int)100; j++) {
      tp[j] = rand() % 3 + 1;
      if (tp[j] == 1) val = (val + 1) % p;
      if (tp[j] == 2) val = (val + p - 1) % p;
      if (tp[j] == 3) val = power(val, p - 2);
      if (from.find(val) != from.end()) {
        int tmp = val, la = from[tmp], cnt = j;
        for (; tmp != y;) {
          if ((tmp + 1) % p == la)
            tp[++cnt] = 1;
          else if ((tmp + p - 1) % p == la)
            tp[++cnt] = 2;
          else
            tp[++cnt] = 3;
          tmp = la;
          la = from[tmp];
        }
        printf("%d\n", cnt);
        for (int wzp = (1); wzp <= (int)cnt; wzp++) printf("%d ", tp[wzp]);
        exit(0);
      }
    }
  }
}
