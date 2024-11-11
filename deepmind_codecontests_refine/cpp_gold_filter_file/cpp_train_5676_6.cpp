#include <bits/stdc++.h>
using namespace std;
inline char gc() {
  static const long long L = 233333;
  static char sxd[L], *sss = sxd, *ttt = sxd;
  if (sss == ttt) {
    ttt = (sss = sxd) + fread(sxd, 1, L, stdin);
    if (sss == ttt) {
      return EOF;
    }
  }
  return *sss++;
}
inline char readalpha() {
  char c = gc();
  for (; !isalpha(c); c = gc())
    ;
  return c;
}
inline char readchar() {
  char c = gc();
  for (; c == ' '; c = gc())
    ;
  return c;
}
template <class T>
inline bool read(T& x) {
  bool flg = false;
  char c = gc();
  x = 0;
  for (; !isdigit(c); c = gc()) {
    if (c == '-') {
      flg = true;
    } else if (c == EOF) {
      return false;
    }
  }
  for (; isdigit(c); c = gc()) {
    x = (x << 1) + (x << 3) + (c ^ 48);
  }
  if (flg) {
    x = -x;
  }
  return true;
}
template <class T>
inline void write(T x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x < 10) {
    putchar(x | 48);
    return;
  }
  write(x / 10);
  putchar((x % 10) | 48);
}
const long long maxn = 100005;
long long n, A, cf, cm, m, ans;
struct Alb {
  long long x;
  long long id;
  friend bool operator<(Alb a, Alb b) { return a.x < b.x; }
} xx[maxn];
long long qzh[maxn];
long long tx[maxn];
inline bool pan(long long pla, long long x, long long hv) {
  if (xx[pla].x < x) {
    return pla <= (hv + qzh[pla]) / (double)x;
  }
  if (xx[1].x >= x) {
    return true;
  }
  long long xx = lower_bound(tx + 1, tx + pla + 1, x) - tx - 1;
  return (long double)xx * x - qzh[xx] <= hv;
}
long long AAns[maxn];
int main() {
  read(n), read(A), read(cf), read(cm), read(m);
  for (long long i = 1; i <= n; ++i) {
    read(xx[i].x);
    xx[i].id = i;
  }
  if (n == 1) {
    long long tt = xx[1].x + m;
    if (tt >= A) {
      printf("%lld\n%lld", cf + A * cm, A);
    } else {
      printf("%lld\n%lld", tt * cm, tt);
    }
    return 0;
  }
  sort(xx + 1, xx + n + 1);
  for (long long i = 1; i <= n; ++i) {
    tx[i] = xx[i].x;
    qzh[i] = qzh[i - 1] + xx[i].x;
  }
  long long ans = -2333, fjx = 0, lll = 0;
  for (long long i = 1; i <= n + 1; ++i) {
    if ((long double)(n - i + 1) * A - (qzh[n] - qzh[i - 1]) <= m) {
      long long nowans = 0, tm = m;
      long long xx = (long double)(n - i + 1) * A - (qzh[n] - qzh[i - 1]);
      tm -= xx;
      assert(tm >= 0);
      nowans += (long long)(n - i + 1) * cf;
      long long l = 0, r = A - 1;
      if (i > 1) {
        while (l < r) {
          long long mid = (l + r + 1) >> 1;
          if (pan(i - 1, mid, tm)) {
            l = mid;
          } else {
            r = mid - 1;
          }
        }
        nowans += (long long)l * cm;
      } else {
        nowans += (long long)A * cm;
      }
      if (nowans >= ans) {
        ans = nowans;
        fjx = i;
        lll = l;
      }
    }
  }
  printf("%lld\n", ans);
  for (long long i = 1; i <= n; ++i) {
    if (i < fjx) {
      if (xx[i].x >= lll) {
        AAns[xx[i].id] = xx[i].x;
      } else {
        AAns[xx[i].id] = lll;
      }
    } else {
      AAns[xx[i].id] = A;
    }
  }
  for (long long i = 1; i <= n; ++i) {
    assert(AAns[i] <= A);
    printf("%lld ", AAns[i]);
  }
  return 0;
}
