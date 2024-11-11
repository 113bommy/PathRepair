#include <bits/stdc++.h>
using namespace std;
const int maxn = 200 + 5, inf = 100;
typedef int ary[maxn];
bitset<20000> ntp;
int s = 0, t, n, m = 1, tot = 0, prm[2600], stream = 0;
ary que, numb, a, head, neck;
struct node {
  int don, nxt, rst;
  void ins(int x, int y, int f) {
    don = y;
    rst = f;
    nxt = head[x];
    head[x] = m;
  }
} star[maxn * maxn];
bool BFS() {
  memset(numb, 0xff, sizeof(numb));
  numb[que[0] = s] = 0;
  for (int f = 0, r = 0, now = que[0]; f <= r; now = que[++f]) {
    neck[now] = head[now];
    for (int q = head[now]; q; q = star[q].nxt)
      if (numb[star[q].don] < 0 && star[q].rst) {
        numb[star[q].don] = numb[now] + 1;
        que[++r] = star[q].don;
      }
  }
  return numb[t] < 0 ? 0 : 1;
}
int DFS(int now, int lim) {
  if (now == t) return lim;
  int used = 0;
  for (int q = neck[now]; q && lim > used || (neck[now] = q, 0);
       q = star[q].nxt)
    if (numb[now] + 1 == numb[star[q].don] && star[q].rst) {
      int flow = DFS(star[q].don, min(lim - used, star[q].rst));
      used += flow;
      star[q].rst -= flow;
      star[q ^ 1].rst += flow;
    }
  return used;
}
void prepare() {
  for (int i = 2; i < 20000; i++) {
    if (!ntp[i]) prm[++tot] = i;
    for (int j = 1; j <= tot && i * prm[j] < 20000; j++) {
      ntp[i * prm[j]] = 1;
      if (i % prm[j] == 0) break;
    }
  }
  scanf("%d", &n);
  t = n + 1;
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
      if (!ntp[a[i] + a[j]]) {
        if (a[i] & 1)
          star[++m].ins(i, j, 1), star[++m].ins(j, i, 0);
        else
          star[++m].ins(j, i, 1), star[++m].ins(i, j, 0);
      }
  for (int i = 1; i <= n; i++)
    if (a[i] & 1)
      star[++m].ins(s, i, 2), star[++m].ins(i, s, 0);
    else
      star[++m].ins(i, t, 2), star[++m].ins(t, i, 0);
}
void cir(int now, int num, int ord) {
  numb[now] = num * maxn * maxn + ord * maxn + now;
  for (int q = head[now]; q; q = star[q].nxt)
    if (!numb[star[q].don] &&
        (a[now] & 1 && !star[q].rst || !(a[now] & 1) && star[q].rst))
      cir(star[q].don, num, ord + 1);
}
bool cmp(int a, int b) { return a > b ? 1 : 0; }
int main() {
  prepare();
  while (BFS()) stream += DFS(s, inf);
  if (stream < n) {
    printf("Impossible\n");
    return 0;
  }
  memset(numb, 0, sizeof(numb));
  int cnt = 0;
  for (int i = 1; i <= n; i++)
    if (!numb[i]) cir(i, ++cnt, 1);
  printf("%d\n", cnt);
  sort(numb + 1, numb + n + 1, cmp);
  for (int i = cnt, j = 1; i; i--) {
    printf("%d", numb[j] / maxn % maxn);
    for (; j <= n && numb[j] / maxn / maxn == i; j++)
      printf(" %d", a[numb[j] % maxn]);
    printf("\n");
  }
  return 0;
}
