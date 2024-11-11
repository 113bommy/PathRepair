#include <bits/stdc++.h>
using namespace std;
inline int gi() {
  char c = getchar();
  int x = 0;
  for (; c < '0' || c > '9'; c = getchar())
    ;
  for (; c >= '0' && c <= '9'; c = getchar()) x = (x << 1) + (x << 3) + c - '0';
  return x;
}
const int N = 1e5 + 5;
int n, m, st[N], tp, now, id[N];
long long w[N], ab, as, del[N];
int main() {
  n = gi(), m = gi();
  st[tp = 1] = (now = 1), id[now] = 0;
  while (m--) {
    int op = gi();
    if (op == 1) {
      int k = gi();
      st[tp = 1] = (now = 1);
      ab = as = del[1] = 0;
      w[1] = id[1] = 0;
      n += k;
    }
    if (op == 2) {
      int k = gi();
      ++now;
      del[now] = ab + as * n, id[now] = n;
      for (; tp > 1 &&
             (long double)((ab - del[st[tp - 1]]) - (ab - del[st[tp]])) *
                     (id[now] - id[st[tp]]) <=
                 (long double)((ab - del[st[tp]]) - (ab - del[now])) *
                     (id[st[tp]] - id[st[tp - 1]]);
           --tp)
        ;
      st[++tp] = now;
      if (tp > 1 && (as * id[st[tp - 1]] + ab - del[st[tp - 1]]) <=
                        (as * id[st[tp]] + ab - del[st[tp]]))
        --tp;
      n += k;
    }
    if (op == 3) {
      int b = gi(), s = gi();
      ab += b, as += s;
      for (; tp > 1 && (as * id[st[tp - 1]] + ab - del[st[tp - 1]]) <=
                           (as * id[st[tp]] + ab - del[st[tp]]);
           --tp)
        ;
    }
    printf("%d %lld\n", id[st[tp]] + 1, (as * id[st[tp]] + ab - del[st[tp]]));
  }
}
