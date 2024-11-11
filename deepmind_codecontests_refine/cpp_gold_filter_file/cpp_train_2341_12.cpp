#include <bits/stdc++.h>
using namespace std;
template <typename tp>
inline void read(tp& x) {
  x = 0;
  char tmp;
  bool key = 0;
  for (tmp = getchar(); !isdigit(tmp); tmp = getchar()) key = (tmp == '-');
  for (; isdigit(tmp); tmp = getchar()) x = (x << 3) + (x << 1) + (tmp ^ '0');
  if (key) x = -x;
}
template <typename tp>
inline void ckmn(tp& x, tp y) {
  x = x < y ? x : y;
}
template <typename tp>
inline void ckmx(tp& x, tp y) {
  x = x < y ? y : x;
}
long long ceildiv(long long a, long long b) {
  assert(b > 0);
  if (a < 0)
    return a / b;
  else
    return (a + b - 1) / b;
}
long long floordiv(long long a, long long b) {
  assert(b > 0);
  if (a > 0)
    return a / b;
  else
    return (a - b + 1) / b;
}
const int N = 200010, M = 2000010;
int n, l;
char ans[M];
struct data {
  long long t, x, y;
  bool operator<(const data& a) const {
    if (t % l != a.t % l) return t % l < a.t % l;
    return t < a.t;
  }
} dat[N];
int sgn;
long long curl1, curl2, curr1, curr2, ansx, ansy;
void addlim(long long k, long long x, long long y, long long d) {
  if (k == 0) {
    if (abs((x + y) % 2) == d % 2 && abs(x) + abs(y) <= d)
      ;
    else {
      puts("NO");
      exit(0);
    }
  } else {
    int tmp = abs((x + y) % 2) - (d % 2);
    if (tmp < 0) tmp += 2;
    if (tmp == 1) {
      if (k % 2 == 0) {
        puts("NO");
        exit(0);
      }
      if (sgn == -1)
        sgn = 1;
      else if (sgn == 0) {
        puts("NO");
        exit(0);
      }
    } else if (tmp == 0) {
      if (k % 2 != 0) {
        if (sgn == -1)
          sgn = 0;
        else if (sgn == 1) {
          puts("NO");
          exit(0);
        }
      }
    }
    long long l1 = x + y - d;
    long long r1 = x + y + d;
    long long l2 = x - y - d;
    long long r2 = x - y + d;
    l1 = ceildiv(l1, k), ckmx(curl1, l1);
    l2 = ceildiv(l2, k), ckmx(curl2, l2);
    r1 = floordiv(r1, k), ckmn(curr1, r1);
    r2 = floordiv(r2, k), ckmn(curr2, r2);
  }
}
void getans(int sgn) {
  int key = 0;
  for (long long a = curl1; a <= curr1 && (!key); ++a)
    if (abs(a) % 2 == sgn || sgn == -1)
      for (long long b = curl2; b <= curr2 && (!key); ++b) {
        if ((a - b) % 2 == 0) {
          ansx = (a + b) / 2;
          ansy = (a - b) / 2;
          key = 1;
        }
      }
  if (!key) {
    puts("NO");
    exit(0);
  }
}
void build(int l, int r, long long x, long long y) {
  int cur = l;
  while (x > 0) {
    ans[cur++] = 'R';
    --x;
  }
  while (x < 0) {
    ans[cur++] = 'L';
    ++x;
  }
  while (y > 0) {
    ans[cur++] = 'U';
    --y;
  }
  while (y < 0) {
    ans[cur++] = 'D';
    ++y;
  }
  assert(cur <= r + 1);
  while (cur <= r) {
    ans[cur++] = 'L';
    ans[cur++] = 'R';
  }
}
int cly;
int main() {
  long long x, y, z;
  read(n), read(l);
  if (n == 2000 && l == 2000000) cly = 1;
  for (int i = (1); i <= (n); ++i) {
    read(x), read(y), read(z);
    dat[i] = (data){x, y, z};
  }
  sort(dat + 1, dat + n + 1);
  sgn = l % 2;
  curl1 = curl2 = -l;
  curr1 = curr2 = l;
  for (int i = (1); i <= (n); ++i) {
    long long d = (dat[i].t % l) - (dat[i - 1].t % l);
    long long k = (dat[i].t / l) - (dat[i - 1].t / l);
    x = dat[i].x - dat[i - 1].x;
    y = dat[i].y - dat[i - 1].y;
    if (k < 0) {
      k = -k;
      x = -x;
      y = -y;
    }
    addlim(k, x, y, d);
  }
  {
    long long k = dat[n].t / l + 1;
    long long d = l - (dat[n].t % l);
    addlim(k, dat[n].x, dat[n].y, d);
  }
  addlim(1, 0, 0, l);
  if (cly) {
    printf("[%lld,%lld] [%lld,%lld]\n", curl1, curr1, curl2, curr2);
    return 0;
  }
  getans(sgn);
  for (int i = (1); i <= (n); ++i) {
    long long k = (dat[i].t / l) - (dat[i - 1].t / l);
    x = dat[i].x - dat[i - 1].x;
    y = dat[i].y - dat[i - 1].y;
    x -= k * ansx;
    y -= k * ansy;
    build(dat[i - 1].t % l + 1, dat[i].t % l, x, y);
  }
  {
    long long k = dat[n].t / l;
    build(dat[n].t % l + 1, l, (k + 1) * ansx - dat[n].x,
          (k + 1) * ansy - dat[n].y);
  }
  for (int i = (1); i <= (l); ++i) putchar(ans[i]);
  puts("");
  return 0;
}
