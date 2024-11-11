#include <bits/stdc++.h>
using namespace std;
template <typename T>
void Read(T &cn) {
  char c;
  long long sig = 1;
  while (!isdigit(c = getchar()))
    if (c == '-') sig = -1;
  cn = c - 48;
  while (isdigit(c = getchar())) cn = cn * 10 + c - 48;
  cn *= sig;
}
template <typename T>
void Write(T cn) {
  if (cn < 0) {
    putchar('-');
    cn = 0 - cn;
  }
  long long wei = 0;
  T cm = 0;
  long long cx = cn % 10;
  cn /= 10;
  while (cn) cm = cm * 10 + cn % 10, cn /= 10, wei++;
  while (wei--) putchar(cm % 10 + 48), cm /= 10;
  putchar(cx + 48);
}
template <typename T>
void Min(T &cn, T cm) {
  cn = cn > cm ? cm : cn;
}
template <typename T>
void Max(T &cn, T cm) {
  cn = cn < cm ? cm : cn;
}
struct xun {
  long long l, r, ci;
  inline friend bool operator<(xun a, xun b) { return a.r < b.r; }
  void getit(long long cn) {
    Read(l);
    Read(r);
    ci = cn;
  }
};
struct qwe {
  long long zhi, dax, chang;
  void mk(long long cn) { zhi = dax = cn; }
};
xun b[1000000 + 1];
long long ans[1000000 + 1];
long long n, m;
qwe a[1000000 + 1];
long long fa[1000000 + 1];
long long qz[1000000 + 1], mi[1000000 + 1], nim[1000000 + 1];
long long he[1000000 + 1];
long long get_fa(long long cn) {
  return cn == fa[cn] ? cn : fa[cn] = get_fa(fa[cn]);
}
long long ksm(long long cn, long long cm) {
  long long ans = 1;
  while (cm)
    ans = ans * (1 + (cn - 1) * (cm & 1)) % 1000000007,
    cn = cn * cn % 1000000007, cm >>= 1;
  return ans;
}
void yuchu(long long cn) {
  mi[0] = 1;
  mi[1] = 2;
  nim[0] = 1;
  nim[1] = ksm(2, 1000000007 - 2);
  for (long long i = 2; i <= cn; i++)
    mi[i] = mi[i - 1] * mi[1] % 1000000007,
    nim[i] = nim[i - 1] * nim[1] % 1000000007;
}
void weihu_he(long long cn) {
  long long lin = get_fa(cn);
  he[lin] = (he[get_fa(lin - 1)] + a[lin].zhi * (1 + (lin != 1))) % 1000000007;
}
long long jia(long long cn, long long cm, long long cx) {
  if (cx >= 62) return (1ll << 62);
  if ((((1ll << 62) - cn) >> cx) <= cm) return (1ll << 62);
  long long guo = cn + cm * (1ll << cx);
  return min(guo, (1ll << 62));
}
void weihu_a(long long cn) {
  a[cn].chang = 1;
  if (cn == 1) return;
  while (cn != 1 && a[cn].dax >= 0) {
    long long lin = get_fa(cn - 1);
    fa[cn] = lin;
    a[lin].zhi = (a[lin].zhi + a[cn].zhi * mi[a[lin].chang]) % 1000000007;
    a[lin].dax = jia(a[lin].dax, a[cn].dax, a[lin].chang);
    a[lin].chang = a[lin].chang + a[cn].chang;
    cn = lin;
  }
}
long long suan(long long cn, long long cm) {
  long long lin = get_fa(cn);
  long long lin2 = lin + a[lin].chang - 1;
  long long lin1 = get_fa(cm);
  return ((he[lin1] - he[lin] +
           (qz[lin2] - qz[cn - 1] + 1000000007) % 1000000007 * nim[cn - 1] %
               1000000007 +
           1000000007) %
              1000000007 +
          1000000007) %
         1000000007;
}
signed main() {
  Read(n);
  Read(m);
  for (long long i = 1; i <= n; i++) {
    long long bx;
    Read(bx);
    a[i].mk(bx);
    fa[i] = i;
  }
  for (long long i = 1; i <= m; i++) b[i].getit(i);
  yuchu(n);
  qz[0] = 0;
  for (long long i = 1; i <= n; i++)
    qz[i] = (qz[i - 1] + a[i].zhi * mi[i - 1]) % 1000000007;
  sort(b + 1, b + m + 1);
  long long xian = 0;
  he[0] = 0;
  for (long long i = 1; i <= n; i++) {
    weihu_a(i);
    weihu_he(i);
    while (xian < m && b[xian + 1].r == i)
      xian++, ans[b[xian].ci] = suan(b[xian].l, i);
  }
  for (long long i = 1; i <= m; i++) Write(ans[i]), puts("");
  return 0;
}
