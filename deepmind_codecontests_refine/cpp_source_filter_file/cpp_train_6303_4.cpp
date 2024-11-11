#include <bits/stdc++.h>
using namespace std;
struct so {
  long long t, u, v, w;
};
int q, dem = 0;
so m[1005];
long long kq, canh[1005][1005];
void tao(int a) {
  int x = m[a].u, y = m[a].v;
  while (x != y) {
    if (x > y) {
      canh[a][0]++;
      int p = canh[a][0];
      canh[a][p] = x - 1;
      x /= 2;
    } else {
      canh[a][0]++;
      int p = canh[a][0];
      canh[a][p] = y - 1;
      y /= 2;
    }
  }
  sort(canh[a] + 1, canh[a] + canh[a][0] + 1);
}
bool pp(long long a, long long b) { return (a < b); }
void capnhat(int a, int b) {
  int n = canh[b][0], p = canh[a][0];
  for (int i = 1; i <= n; i++) {
    int vt =
        std::lower_bound(canh[a] + 1, canh[a] + p, canh[b][i], pp) - canh[a];
    if (canh[b][i] == canh[a][vt]) kq += m[b].w;
  }
}
void xuly() {
  for (int i = 1; i <= q; i++)
    if (m[i].t == 2) {
      kq = 0;
      for (int j = 1; j <= i - 1; j++)
        if (m[j].t == 1) capnhat(i, j);
      printf("I64d\n", kq);
    }
}
int main() {
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    scanf("%I64d", &m[i].t);
    if (m[i].t == 1)
      scanf("%I64d%I64d%I64d", &m[i].u, &m[i].v, &m[i].w);
    else
      scanf("%I64d%I64d", &m[i].u, &m[i].v);
  }
  for (int i = 1; i <= q; i++) tao(i);
  xuly();
  return 0;
}
