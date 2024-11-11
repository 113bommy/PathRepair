#include <bits/stdc++.h>
using namespace std;
namespace Base {
const int inf = 0x3f3f3f3f, INF = 0x7fffffff;
const long long infll = 0x3f3f3f3f3f3f3f3fll, INFll = 0x7fffffffffffffffll;
template <typename T>
void read(T &x) {
  x = 0;
  int fh = 1;
  double num = 1.0;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') fh = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  if (ch == '.') {
    ch = getchar();
    while (isdigit(ch)) {
      num /= 10;
      x = x + num * (ch - '0');
      ch = getchar();
    }
  }
  x = x * fh;
}
template <typename T>
void chmax(T &x, T y) {
  x = x < y ? y : x;
}
template <typename T>
void chmin(T &x, T y) {
  x = x > y ? y : x;
}
}  // namespace Base
using namespace Base;
const int N = 100010;
int n, a[N], q[N], use[N], pre[N], prel[N], prem[N], prer[N], num, l[N], m[N],
    r[N];
void force(int *a, int n, int id) {
  int tmp = 0;
  for (int i = 1; i <= n; i++) tmp = tmp + (a[i] << (i - 1));
  int pl = 1, pr = 1;
  q[1] = 0;
  use[0] = true;
  while (pl <= pr) {
    int x = q[pl++];
    for (int i = 1; i <= n; i++)
      for (int j = i + 1; j <= n; j++) {
        int k = j + (j - i);
        if (k > n) continue;
        int nxt = x ^ (1 << (i - 1)) ^ (1 << (j - 1)) ^ (1 << (k - 1));
        if (use[nxt] == false) {
          q[++pr] = nxt;
          use[nxt] = true;
          pre[nxt] = x;
          prel[nxt] = i;
          prem[nxt] = j, prer[nxt] = k;
        }
      }
  }
  if (use[tmp] == false) {
    printf("NO\n");
    exit(0);
  }
  printf("YES\n");
  while (tmp != 0) {
    num++;
    l[num] = prel[tmp] + id, m[num] = prem[tmp] + id, r[num] = prer[tmp] + id;
    tmp = pre[tmp];
  }
  printf("%d\n", num);
  for (int i = 1; i <= num; i++) printf("%d %d %d\n", l[i], m[i], r[i]);
}
void doit(int nl, int nm, int nr) {
  num++;
  l[num] = nl, m[num] = nm, r[num] = nr;
  a[nl] ^= 1, a[nm] ^= 1, a[nr] ^= 1;
}
int main() {
  read(n);
  for (int i = 1; i <= n; i++) read(a[i]);
  int pl = 1, pr = n;
  while (pr - pl + 1 > 12) {
    if (a[pl] == 0) {
      pl++;
      continue;
    }
    if (a[pr] == 0) {
      pr--;
      continue;
    }
    if (a[pl] + a[pl + 1] + a[pl + 2] == 3) {
      doit(pl, pl + 1, pr + 2);
      continue;
    }
    if (a[pr] + a[pr - 1] + a[pr - 2] == 3) {
      doit(pr - 2, pr - 1, pr);
      continue;
    }
    if ((pr - pl) % 2 == 0) {
      doit(pl, (pl + pr) / 2, pr);
      continue;
    }
    if (a[pl] != a[pl + 1] && a[pl] == a[pl + 2]) {
      doit(pl, pl + 2, pl + 4);
      continue;
    }
    if (a[pr] != a[pr - 1] && a[pr] == a[pr - 2]) {
      doit(pr - 4, pr - 2, pr);
      continue;
    }
    doit(pl, (pl + pr - 1) / 2, pr - 1);
  }
  if (n <= 12)
    force(a, n, 0);
  else
    force(a + pl - 1, 12, pl - 1);
  return 0;
}
