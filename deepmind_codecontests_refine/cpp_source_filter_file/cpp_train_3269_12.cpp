#include <bits/stdc++.h>
using namespace std;
int n, m, d;
const int MAXN = 100005;
int sn[MAXN];
int ef[MAXN];
int et[2 * MAXN];
int en[2 * MAXN];
int ec[MAXN];
int sec[MAXN];
int vis[MAXN];
int parent[MAXN];
int stk[MAXN];
int disu[MAXN];
int disd1[MAXN];
int disd1i[MAXN];
int disd2[MAXN];
int disd2i[MAXN];
int main() {
  scanf("%d %d %d", &n, &m, &d);
  for (int i = 0; i < m; i++) {
    int t;
    scanf("%d", &t);
    sn[t] = 1;
  }
  for (int i = 0; i < (n - 1); i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    et[2 * i + 1] = b;
    en[2 * i + 1] = ef[a];
    ef[a] = 2 * i + 1;
    et[2 * i + 2] = a;
    en[2 * i + 2] = ef[b];
    ef[b] = 2 * i + 2;
  }
  vis[1] = 1;
  stk[0] = 1;
  int stkl = 0;
  int stkw = 1;
  while (stkl < n) {
    int cpos = stk[stkl++];
    int t = ef[cpos];
    while (t) {
      int tg = et[t];
      if (vis[tg] == 0) {
        vis[tg] = 1;
        parent[tg] = cpos;
        stk[stkw++] = tg;
      }
      t = en[t];
    }
  }
  memset(disd1, 0x7e, sizeof(disd1));
  memset(disd2, 0x7e, sizeof(disd2));
  for (int i = n - 1; i >= 0; i--) {
    int cp = stk[i];
    if (disd1[cp] < 0 && sn[cp]) {
      disd1[cp] = 0;
    }
    if (disd1[cp] >= 0) {
      int d2 = disd1[cp] + 1;
      int cpar = parent[cp];
      if (d2 >= disd1[cpar]) {
        disd2[cpar] = disd1[cpar];
        disd2i[cpar] = disd1i[cpar];
        disd1[cpar] = d2;
        disd1i[cpar] = cp;
      } else if (d2 >= disd2[cpar]) {
        disd2[cpar] = d2;
        disd2i[cpar] = cp;
      }
    }
  }
  disu[0] = -500000;
  disd1[0] = -500000;
  disd2[0] = -500000;
  disu[1] = 0;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int cp = stk[i];
    int mxd = -300000;
    int prn = parent[cp];
    mxd = max(mxd, disu[prn] + 1);
    if (disd1i[prn] == cp)
      mxd = max(mxd, disd2[prn] + 1);
    else
      mxd = max(mxd, disd1[prn] + 1);
    if (mxd < 0 && sn[cp]) mxd = 0;
    disu[cp] = mxd;
    mxd = max(mxd, disd1[cp]);
    if (mxd >= 0 && mxd <= d) {
      ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
