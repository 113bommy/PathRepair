#include <bits/stdc++.h>
using namespace std;
const int N = 300010;
const int Q = 600010;
int n, q, poz[N], pc;
char a[Q], b[N];
int sf[21][Q], v[Q], nr[Q], cs[N], cd[N], siz[N];
struct ss {
  int x, y, poz;
};
ss x[Q];
bool cmp(ss a, ss b) {
  if (a.x == b.x) return a.y < b.y;
  return a.x < b.x;
}
void calcsuf() {
  int i, j;
  for (i = 0; i < pc; ++i) sf[0][i] = a[i];
  for (j = 1; (1 << j) <= 2 * pc; ++j) {
    int l = (1 << (j - 1));
    for (i = 0; i < pc; ++i) {
      x[i].x = sf[j - 1][i];
      x[i].y = (i + l < pc ? sf[j - 1][i + l] : -1);
      x[i].poz = i;
    }
    sort(x, x + pc, cmp);
    for (i = 0; i < pc; ++i) {
      if (!i || x[i].x != x[i - 1].x || x[i].y != x[i - 1].y)
        sf[j][x[i].poz] = i;
      else
        sf[j][x[i].poz] = sf[j][x[i - 1].poz];
    }
  }
  --j;
  for (i = 0; i < pc; ++i) {
    v[sf[j][i]] = i;
    nr[i] = sf[j][i];
  }
}
int rmq[21][Q], p2[Q];
int lcp(int a, int b) {
  int k, r = 0;
  for (k = 20; k >= 0; --k)
    if ((1 << k) + max(a, b) <= pc && sf[k][a] == sf[k][b]) {
      r += (1 << k);
      a += (1 << k);
      b += (1 << k);
    }
  return r;
}
int elmin(int poz1, int poz2) {
  if (poz1 > poz2) swap(poz1, poz2);
  int l = p2[poz2 - poz1 + 1];
  return min(rmq[l][poz1], rmq[l][poz2 - (1 << l) + 1]);
}
void calcint() {
  int i, j, pas;
  for (i = 2; i < Q; ++i) p2[i] = p2[i / 2] + 1;
  for (i = 0; i < pc - 1; ++i) rmq[0][i] = lcp(v[i], v[i + 1]);
  for (i = 1; (1 << i) <= pc; ++i)
    for (j = 0; j < pc - (1 << i); ++j)
      rmq[i][j] = min(rmq[i - 1][j], rmq[i - 1][j + (1 << (i - 1))]);
  for (i = 1; i <= n; ++i) {
    int po = nr[poz[i]];
    pas = (1 << 21);
    for (j = 0; pas; pas /= 2)
      if (po - 1 - (j + pas) >= 0 &&
          elmin(po - 1 - (j + pas), po - 1) >= siz[i])
        j += pas;
    cs[i] = po - 1 - j;
    if (rmq[0][po - 1] < siz[i]) cs[i] = po;
    pas = (1 << 21);
    for (j = 0; pas; pas /= 2)
      if (po + (j + pas) < pc - 1 && elmin(po, po + j + pas) >= siz[i])
        j += pas;
    cd[i] = po + j + 1;
    if (rmq[0][po] < siz[i]) cd[i] = po;
  }
}
int l[Q], r[Q], k[Q], p[Q], rez[Q];
bool cmp1(int a, int b) { return l[a] < l[b]; }
bool cmp2(int a, int b) { return r[a] < r[b]; }
int aib[Q];
void update(int poz) {
  ++poz;
  for (; poz <= pc; poz += (poz & (-poz))) aib[poz]++;
}
int cal(int poz) {
  int r = 0;
  for (; poz; poz -= (poz & (-poz))) r += aib[poz];
  return r;
}
int sum(int px, int py) {
  ++px;
  ++py;
  return cal(py) - cal(px - 1);
}
void calcrez() {
  int i, j, ll;
  sort(p + 1, p + q + 1, cmp1);
  for (i = 1, j = 1; i <= q; ++i) {
    while (l[p[i]] > j) {
      for (ll = 0; ll < siz[j]; ++ll) update(nr[poz[j] + ll]);
      ++j;
    }
    rez[p[i]] -= sum(cs[k[p[i]]], cd[k[p[i]]]);
  }
  memset(aib, 0, sizeof(aib));
  sort(p + 1, p + q + 1, cmp2);
  for (i = q, j = n; i; --i) {
    while (r[p[i]] < j) {
      for (ll = 0; ll < siz[j]; ++ll) update(nr[poz[j] + ll]);
      --j;
    }
    rez[p[i]] -= sum(cs[k[p[i]]], cd[k[p[i]]]);
  }
}
int main() {
  int i;
  cin >> n >> q;
  for (i = 1; i <= n; ++i) {
    cin >> b;
    ++pc;
    siz[i] = strlen(b);
    poz[i] = pc;
    for (int j = 0; j < siz[i]; ++j) a[pc++] = b[j];
  }
  calcsuf();
  calcint();
  for (i = 1; i <= q; ++i) {
    scanf("%d%d%d", &l[i], &r[i], &k[i]);
    p[i] = i;
    rez[i] = cd[k[i]] - cs[k[i]] + 1;
  }
  calcrez();
  for (i = 1; i <= q; ++i) cout << rez[i] << "\n";
  return 0;
}
