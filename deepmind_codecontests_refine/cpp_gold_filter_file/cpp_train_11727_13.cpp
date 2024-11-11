#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
char s[N], t[N];
int cbs[N], cbt[N];
int pbs[N], pbt[N];
void go(char *s, int *cntB, int *prvB) {
  prvB[0] = 0;
  for (int i = 1; s[i]; i++) {
    cntB[i] = cntB[i - 1] + (s[i] != 'A');
    prvB[i] = (s[i] != 'A' ? i : prvB[i - 1]);
  }
}
int main() {
  scanf("%s", s + 1);
  scanf("%s", t + 1);
  go(s, cbs, pbs);
  go(t, cbt, pbt);
  int q, a, b, c, d;
  scanf("%d", &q);
  while (q--) {
    scanf("%d%d%d%d", &a, &b, &c, &d);
    int counts = cbs[b] - cbs[a - 1];
    int countt = cbt[d] - cbt[c - 1];
    int sufs = b - max(pbs[b], a - 1);
    int suft = d - max(pbt[d], c - 1);
    if (counts > countt || (countt - counts) % 2)
      putc('0', stdout);
    else if (counts == 0 && countt != 0 && (sufs <= suft))
      putc('0', stdout);
    else if (counts == countt && ((sufs < suft) || (sufs - suft) % 3))
      putc('0', stdout);
    else if (counts < countt && (sufs < suft))
      putc('0', stdout);
    else
      putc('1', stdout);
  }
  puts("");
  return 0;
}
