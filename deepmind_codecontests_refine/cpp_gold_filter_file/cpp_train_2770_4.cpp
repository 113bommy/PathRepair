#include <bits/stdc++.h>
using namespace std;
int n, k, m, p, now, pos, tid, x;
struct xy {
  int cnt, las, id;
} a[300], b[300];
bool cmp(const xy& a1, const xy& a2) {
  return a1.cnt == a2.cnt ? a1.las < a2.las : a1.cnt > a2.cnt;
}
int doit() {
  int i, l, t;
  for (i = 1; i <= n; i++) b[i] = a[i];
  for (pos = 1; b[pos].id != now; pos++)
    ;
  b[pos].cnt += p;
  if (p) {
    tid = m;
    b[pos].las = m + p;
  }
  sort(b + 1, b + n + 1, cmp);
  for (pos = 1; b[pos].id != now; pos++)
    ;
  if (pos > k || b[pos].cnt == 0) {
    printf("3 ");
    return 0;
  }
  for (i = 1; i <= n; i++) b[i] = a[i];
  for (pos = 1; b[pos].id != now; pos++)
    ;
  for (l = p, t = pos + 1; l && t <= n; t++)
    for (; l && (b[t].cnt == b[pos].cnt ? b[t].las >= b[pos].las
                                        : b[t].cnt < b[pos].cnt);
         l--) {
      b[t].cnt++;
      b[t].las = ++tid;
    }
  sort(b + 1, b + n + 1, cmp);
  for (pos = 1; b[pos].id != now; pos++)
    ;
  if (pos > k || b[pos].cnt == 0) {
    printf("2 ");
    return 0;
  }
  printf("1 ");
}
int main() {
  int i;
  cin >> n >> k >> p >> m;
  p -= m;
  for (i = 1; i <= m; i++) {
    cin >> x;
    a[x].cnt++;
    a[x].las = i;
  }
  for (i = 1; i <= n; i++) a[i].id = i;
  sort(a + 1, a + n + 1, cmp);
  now = 1;
  for (i = 1; i <= n; i++) {
    doit();
    now = i + 1;
  }
  return 0;
}
