#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
inline T1 max(T1 a, T2 b) {
  return a < b ? b : a;
}
template <typename T1, typename T2>
inline T1 min(T1 a, T2 b) {
  return a < b ? a : b;
}
const char lf = '\n';
namespace ae86 {
const int bufl = 1 << 15;
char buf[bufl], *s = buf, *t = buf;
inline int fetch() {
  if (s == t) {
    t = (s = buf) + fread(buf, 1, bufl, stdin);
    if (s == t) return EOF;
  }
  return *s++;
}
inline int ty() {
  int a = 0;
  int b = 1, c = fetch();
  while (!isdigit(c)) b ^= c == '-', c = fetch();
  while (isdigit(c)) a = a * 10 + c - 48, c = fetch();
  return b ? a : -a;
}
}  // namespace ae86
using ae86::ty;
const int _ = 150007;
int cxkdlq;
struct cxk {
  int num, val[5], cnt[5];
  cxk() { num = 0, memset(val, 0, sizeof(val)), memset(cnt, 0, sizeof(cnt)); }
  cxk(int bas, int len) { num = 1, val[0] = bas, cnt[0] = len; }
  friend cxk operator+(cxk a, cxk b) {
    for (int i = 0; i < a.num; i++) {
      int got = 0;
      for (int j = 0; j < b.num; j++)
        if (a.val[i] == b.val[j]) {
          b.cnt[j] += a.cnt[i], got = 0;
          break;
        }
      if (got) continue;
      if (b.num < cxkdlq) {
        b.val[b.num] = a.val[i], b.cnt[b.num] = a.cnt[i], b.num++;
        continue;
      }
      int x = 0;
      for (int j = 1; j < b.num; j++)
        if (b.cnt[j] < b.cnt[x]) x = j;
      if (a.cnt[i] < b.cnt[x]) {
        for (int j = 0; j < b.num; j++) b.cnt[j] -= a.cnt[i];
      } else {
        int temp = b.cnt[x];
        b.val[x] = a.val[i], b.cnt[x] = a.cnt[i];
        for (int j = 0; j < b.num; j++) b.cnt[j] -= temp;
      }
    }
    return b;
  }
};
struct sgt {
  static const int _t = _ << 2;
  cxk t[_t];
  int len[_t], tch[_t];
  void up(int x) { t[x] = t[(x << 1)] + t[(x << 1 | 1)]; }
  void putch(int x, int d) { t[x] = cxk(d, len[x]), tch[x] = d; }
  void dwn(int x) {
    if (tch[x] != 0)
      putch((x << 1), tch[x]), putch((x << 1 | 1), tch[x]), tch[x] = 0;
  }
  void plant(int x, int l, int r, int val[]) {
    len[x] = r - l + 1, tch[x] = 0;
    if (l == r) {
      t[x] = cxk(val[l], 1);
      return;
    }
    plant((x << 1), l, ((l + r) >> 1), val),
        plant((x << 1 | 1), ((l + r) >> 1) + 1, r, val), up(x);
  }
  void change(int x, int l, int r, int tl, int tr, int d) {
    if (tl <= l && r <= tr) {
      putch(x, d);
      return;
    }
    dwn(x);
    if (tl <= ((l + r) >> 1)) change((x << 1), l, ((l + r) >> 1), tl, tr, d);
    if (tr > ((l + r) >> 1))
      change((x << 1 | 1), ((l + r) >> 1) + 1, r, tl, tr, d);
    up(x);
  }
  cxk finder(int x, int l, int r, int tl, int tr) {
    if (tl <= l && r <= tr) return t[x];
    dwn(x);
    if (tr <= ((l + r) >> 1))
      return finder((x << 1), l, ((l + r) >> 1), tl, tr);
    if (tl > ((l + r) >> 1))
      return finder((x << 1 | 1), ((l + r) >> 1) + 1, r, tl, tr);
    return finder((x << 1), l, ((l + r) >> 1), tl, tr) +
           finder((x << 1 | 1), ((l + r) >> 1) + 1, r, tl, tr);
  }
} t;
int n, m, sl, val[_];
int main() {
  ios::sync_with_stdio(0), cout.tie(nullptr);
  n = ty(), m = ty(), sl = ty(), cxkdlq = 100 / sl;
  for (int i = 1; i <= n; i++) val[i] = ty();
  t.plant(1, 1, n, val);
  for (int qq = 1; qq <= m; qq++) {
    int op = ty();
    if (op == 1) {
      int l = ty(), r = ty(), x = ty();
      t.change(1, 1, n, l, r, x);
    } else {
      int l = ty(), r = ty();
      cxk dlq = t.finder(1, 1, n, l, r);
      cout << dlq.num;
      for (int i = 0; i < dlq.num; i++) cout << ' ' << dlq.val[i];
      cout << lf;
    }
  }
  return 0;
}
