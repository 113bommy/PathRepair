#include <bits/stdc++.h>
using namespace std;
template <typename T>
void maxtt(T &t1, T t2) {
  t1 = max(t1, t2);
}
template <typename T>
void mintt(T &t1, T t2) {
  t1 = min(t1, t2);
}
bool debug = 0;
int n, m, k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
string direc = "RDLU";
long long ln, lk, lm;
void etp(bool f = 0) {
  puts(f ? "YES" : "NO");
  exit(0);
}
void addmod(int &x, int y, int mod = 998244353) {
  assert(y >= 0);
  x += y;
  if (x >= mod) x -= mod;
  assert(x >= 0 && x < mod);
}
void et(int x = -1) {
  printf("%d\n", x);
  exit(0);
}
long long fastPow(long long x, long long y, int mod = 998244353) {
  long long ans = 1;
  while (y > 0) {
    if (y & 1) ans = (x * ans) % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return ans;
}
long long gcd1(long long x, long long y) { return y ? gcd1(y, x % y) : x; }
struct mb {
  int a[3], mx[3], mi[3];
  void rd() {
    for (int(i) = 0; (i) < (int)(3); (i)++) scanf("%d", a + i);
  }
} H, L, tmp, tr[200105], mp[200105];
int ls[200105], rs[200105], cnt, opt;
bool isIn(mb &a, mb &x, mb &y) {
  for (int(j) = 0; (j) < (int)(3); (j)++) {
    if (a.a[j] < x.a[j] || a.a[j] > y.a[j]) return 0;
  }
  return 1;
}
bool isOut(mb &a, mb &x, mb &y) {
  for (int(j) = 0; (j) < (int)(3); (j)++) {
    if (a.mx[j] < x.a[j] || a.mi[j] > y.a[j]) return 1;
  }
  return 0;
}
int cmp(mb a, mb b) { return a.a[opt] < b.a[opt]; }
void up(int x) {
  for (int(j) = 0; (j) < (int)(3); (j)++) {
    tr[x].mx[j] = tr[x].a[j];
    tr[x].mi[j] = tr[x].a[j];
    if (ls[x]) {
      maxtt(tr[x].mx[j], tr[ls[x]].mx[j]);
      mintt(tr[x].mi[j], tr[ls[x]].mi[j]);
    }
    if (rs[x]) {
      maxtt(tr[x].mx[j], tr[rs[x]].mx[j]);
      mintt(tr[x].mi[j], tr[rs[x]].mi[j]);
    }
  }
}
void build(int &rt, int l, int r, int dim) {
  if (r < l) return;
  if (rt == 0) rt = ++cnt;
  int mid = (l + r) / 2;
  opt = dim;
  nth_element(mp + l, mp + mid, mp + r + 1, cmp);
  tr[rt] = mp[mid];
  build(ls[rt], l, mid - 1, (dim + 1) % 3);
  build(rs[rt], mid + 1, r, (dim + 1) % 3);
  up(rt);
}
bool qy(int rt, mb &a, mb &b) {
  if (rt == 0) return 0;
  if (isIn(tr[rt], a, b)) return 1;
  if (isOut(tr[rt], a, b)) return 0;
  if (qy(ls[rt], a, b)) return 1;
  return qy(rs[rt], a, b);
}
void fmain(int ID) {
  L.rd();
  scanf("%d%d%d", &n, &m, &k);
  for (int(i) = 1; (i) <= (int)(n); (i)++) {
    tmp.rd();
    for (int(j) = 0; (j) < (int)(3); (j)++) {
      mintt(L.a[j], tmp.a[j]);
      maxtt(H.a[j], tmp.a[j]);
    }
  }
  for (int(i) = 1; (i) <= (int)(m); (i)++) {
    mp[i].rd();
    if (isIn(mp[i], L, H)) {
      puts("INCORRECT");
      return;
    }
  }
  puts("CORRECT");
  int rt = 0;
  build(rt, 1, m, 0);
  for (int(i) = 1; (i) <= (int)(k); (i)++) {
    tmp.rd();
    if (isIn(tmp, L, H)) {
      puts("OPEN");
      continue;
    }
    mb x, y;
    for (int(j) = 0; (j) < (int)(3); (j)++) {
      x.a[j] = min(L.a[j], tmp.a[j]);
      y.a[j] = max(L.a[j], tmp.a[j]);
    }
    puts(qy(rt, x, y) ? "CLOSED" : "UNKNOWN");
  }
}
int main() {
  int t = 1;
  for (int(i) = 1; (i) <= (int)(t); (i)++) {
    fmain(i);
  }
  return 0;
}
