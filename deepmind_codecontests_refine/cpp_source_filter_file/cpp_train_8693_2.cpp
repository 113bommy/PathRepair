#include <bits/stdc++.h>
using namespace std;
template <typename T>
T in() {
  char ch;
  T n = 0;
  bool ng = false;
  while (1) {
    ch = getchar();
    if (ch == '-') {
      ng = true;
      ch = getchar();
      break;
    }
    if (ch >= '0' && ch <= '9') break;
  }
  while (1) {
    n = n * 10 + (ch - '0');
    ch = getchar();
    if (ch < '0' || ch > '9') break;
  }
  return (ng ? -n : n);
}
template <typename T>
inline T POW(T B, T P) {
  if (P == 0) return 1;
  if (P & 1)
    return B * POW(B, P - 1);
  else
    return (POW(B, P / 2) * POW(B, P / 2));
}
template <typename T>
inline T Gcd(T a, T b) {
  if (a < 0) return Gcd(-a, b);
  if (b < 0) return Gcd(a, -b);
  return (b == 0) ? a : Gcd(b, a % b);
}
template <typename T>
inline T Lcm(T a, T b) {
  if (a < 0) return Lcm(-a, b);
  if (b < 0) return Lcm(a, -b);
  return a * (b / Gcd(a, b));
}
long long Bigmod(long long base, long long power, long long MOD) {
  long long ret = 1;
  while (power) {
    if (power & 1) ret = (ret * base) % MOD;
    base = (base * base) % MOD;
    power >>= 1;
  }
  return ret;
}
bool isVowel(char ch) {
  ch = toupper(ch);
  if (ch == 'A' || ch == 'U' || ch == 'I' || ch == 'O' || ch == 'E')
    return true;
  return false;
}
long long ModInverse(long long number, long long MOD) {
  return Bigmod(number, MOD - 2, MOD);
}
bool isConst(char ch) {
  if (isalpha(ch) && !isVowel(ch)) return true;
  return false;
}
int toInt(string s) {
  int sm;
  stringstream second(s);
  second >> sm;
  return sm;
}
struct z {
  int x, up, dw, f;
  z() {}
  z(int _, int __, int ___, int first) { x = _, up = __, dw = ___, f = first; }
  bool operator<(const z &p) const {
    if (x < p.x)
      return true;
    else if (x == p.x)
      return (f > p.f);
    return false;
  }
};
int N;
z ar[400007];
struct data {
  int x, y, yy;
  data() {}
  data(int _, int __, int ___) { x = _, y = __, yy = ___; }
  bool operator<(const data &p) const {
    if (x < p.x)
      return true;
    else if (x == p.x) {
      if (y < p.y)
        return true;
      else if (y == p.y)
        return (yy < p.yy);
    }
    return false;
  }
};
struct data1 {
  int y, x, xx;
  data1() {}
  data1(int _, int __, int ___) { y = _, x = __, xx = ___; }
  bool operator<(const data1 &p) const {
    if (y < p.y)
      return true;
    else if (y == p.y) {
      if (x < p.x)
        return true;
      else if (x == p.x)
        return (xx < p.xx);
    }
    return false;
  }
};
data a[400007];
data1 b[400007];
int Ln, L;
int Y[400007], Yid;
int Tree[400007 * 4];
int Cnt[400007 * 4];
void Update(int id, int l, int r, int pos, int v) {
  if (l == r) {
    Cnt[id] += v;
    if (Cnt[id] > 0)
      Tree[id] = 1;
    else
      Tree[id] = 0;
    return;
  }
  int mid = (l + r) / 2;
  int lft = 2 * id;
  int rgt = lft + 1;
  if (pos <= mid)
    Update(lft, l, mid, pos, v);
  else
    Update(rgt, mid + 1, r, pos, v);
  Tree[id] = Tree[lft] + Tree[rgt];
}
int Query(int id, int l, int r, int s, int e) {
  if (s <= l && e >= r) return Tree[id];
  int mid = (l + r) / 2;
  int lft = 2 * id;
  int rgt = lft + 1;
  if (e <= mid)
    return Query(lft, l, mid, s, e);
  else if (s > mid)
    return Query(rgt, mid + 1, r, s, e);
  else {
    return Query(lft, l, mid, s, e) + Query(rgt, mid + 1, r, s, e);
  }
}
int main() {
  int n;
  n = in<int>();
  long long int ans = 0;
  for (int i = 1; i <= n; i++) {
    int x, xx, y, yy;
    x = in<int>(), y = in<int>();
    xx = in<int>(), yy = in<int>();
    x += 2000000000, y += 2000000000, xx += 2000000000, yy += 2000000000;
    if (x == xx) {
      if (y > yy) swap(y, yy);
    } else {
      if (x > xx) swap(x, xx);
    }
    if (x == xx) {
      a[++Ln] = data(x, y, yy);
      Y[++Yid] = y;
      Y[++Yid] = yy;
    } else {
      b[++L] = data1(y, x, xx);
      Y[++Yid] = y;
    }
  }
  sort(Y + 1, Y + Yid + 1);
  Yid = unique(Y + 1, Y + Yid + 1) - Y - 1;
  sort(a + 1, a + Ln + 1);
  sort(b + 1, b + L + 1);
  int pv = -1000000;
  int y = -10000, yy = -10000;
  for (int i = 1; i <= Ln; i++) {
    int x = a[i].x;
    if (x != pv) {
      if (y != -10000) {
        ar[++N] = z(pv, y, yy, 1);
      }
      y = a[i].y, yy = a[i].yy;
      pv = x;
    } else {
      if (yy + 1 < a[i].y) {
        ar[++N] = z(x, y, yy, 1);
        y = a[i].y, yy = a[i].yy;
      } else {
        yy = max(yy, a[i].yy);
      }
    }
  }
  if (y != -10000) {
    ar[++N] = z(pv, y, yy, 1);
  }
  pv = -100000;
  int x = -10000, xx = -10000;
  for (int i = 1; i <= L; i++) {
    int y = b[i].y;
    if (y != pv) {
      if (x != -10000) {
        ar[++N] = z(x, pv, xx, 2);
        ar[++N] = z(xx, pv, xx, -1);
      }
      x = b[i].x, xx = b[i].xx;
      pv = y;
    } else {
      if (xx + 1 < b[i].x) {
        ar[++N] = z(x, y, xx, 2);
        ar[++N] = z(xx, y, xx, -1);
        x = b[i].x, xx = b[i].xx;
      } else {
        xx = max(xx, b[i].xx);
      }
    }
  }
  if (x != -10000) {
    ar[++N] = z(x, pv, xx, 2);
    ar[++N] = z(xx, pv, xx, -1);
  }
  sort(ar + 1, ar + N + 1);
  for (int i = 1; i <= N; i++) {
    int id = ar[i].f;
    int lo = lower_bound(Y + 1, Y + 1 + Yid, ar[i].up) - Y;
    int hi = lower_bound(Y + 1, Y + 1 + Yid, ar[i].dw) - Y;
    if (id == 2) {
      Update(1, 1, Yid, lo, 1);
      ans += abs(ar[i].dw - ar[i].x) + 1;
    } else if (id == 1) {
      ans += abs(ar[i].dw - ar[i].up) + 1;
      ans -= Query(1, 1, Yid, lo, hi);
    } else {
      Update(1, 1, Yid, lo, -1);
    }
  }
  printf("%lld\n", ans);
  return 0;
}
