#include <bits/stdc++.h>
using namespace std;
const int NN = 100 + 117;
const int MM = 3000 + 117;
int read() {
  int fl = 1, x;
  char c;
  for (c = getchar(); (c < '0' || c > '9') && c != '-'; c = getchar())
    ;
  if (c == '-') {
    fl = -1;
    c = getchar();
  }
  for (x = 0; c >= '0' && c <= '9'; c = getchar())
    x = (x << 3) + (x << 1) + c - '0';
  return x * fl;
}
void open() { freopen("a.in", "r", stdin); }
void close() {
  fclose(stdin);
  fclose(stdout);
}
const int mod = 1e9 + 7;
long long ksm(long long a, long long b) {
  long long ret = 1;
  for (; b; b >>= 1, a = a * a % mod)
    if (b & 1) ret = ret * a % mod;
  return ret;
}
int m, n;
struct eq {
  long long st, d;
} a[NN][MM];
int d[MM] = {};
int dcnt = 0;
long long in[NN][2] = {};
long long ans[MM] = {};
bool vis[MM] = {};
void dvd(int a) {
  int top = sqrt(a + 1);
  for (int i = 2; i <= top; ++i) {
    if (a % i == 0) {
      d[++dcnt] = i;
      while (a % i == 0) a /= i;
    }
  }
  if (a != 1) d[++dcnt] = a;
}
bool chk() {
  for (int i = 1; i <= n; ++i) {
    long long x = -1;
    for (int j = 1; j <= dcnt; ++j) {
      if (ans[j] < a[i][j].st) return false;
      if (a[i][j].d) {
        if ((ans[j] - a[i][j].st) % a[i][j].d) return false;
        long long now = (ans[j] - a[i][j].st) / a[i][j].d;
        if (x == -1)
          now = x;
        else if (now != x)
          return false;
      } else {
        if (ans[j] != a[i][j].st) return false;
      }
    }
  }
  return true;
}
void makeans(int id, long long x) {
  for (int i = 1; i <= dcnt; ++i) {
    ans[i] = a[id][i].st + a[id][i].d * x;
  }
}
void WA() {
  printf("-1\n");
  exit(0);
}
void AC() {
  long long op = 1;
  for (int i = 1; i <= dcnt; ++i) {
    op = op * ksm(d[i], ans[i]) % mod;
  }
  printf("%lld\n", op);
  exit(0);
}
void judge() {
  if (chk())
    AC();
  else
    WA();
}
long long x[2][3] = {};
int xiao() {
  long long mul1 = x[1][0];
  long long mul2 = x[0][0];
  x[0][0] *= mul1, x[0][1] *= mul1, x[0][2] *= mul1;
  x[1][0] *= mul2, x[1][1] *= mul2, x[1][2] *= mul2;
  x[1][0] -= x[0][0], x[1][1] -= x[0][1], x[1][2] -= x[0][2];
  if (x[1][1] == 0) {
    if (x[1][2] == 0)
      return 1;
    else
      return -1;
  }
  if (x[1][2] % x[1][1]) return -1;
  x[1][2] /= x[1][1];
  if (x[1][2] < 0) return -1;
  x[0][2] -= x[0][1] * x[1][2];
  if (x[0][2] % x[0][0]) return -1;
  x[0][2] /= x[0][0];
  if (x[0][2] < 0) return -1;
  return 0;
}
long long exgcd(long long a, long long &x, long long b, long long &y) {
  if (b == 0) {
    x = 1, y = 0;
    return a;
  }
  long long nx, ny;
  long long g = exgcd(b, nx, a % b, ny);
  x = ny;
  y = nx - a / b * ny;
  return g;
}
long long mul(long long a, long long b, long long mod) {
  long long ret = 0;
  if (b < 0) b = -b, a = -a;
  for (; b; b >>= 1, a = (a + a) % mod) {
    if (b & 1) ret = (ret + a) % mod;
  }
  return ret;
}
bool bind(eq &a, eq b) {
  long long x, y;
  long long g = exgcd(a.d, x, b.d, y);
  long long c = b.st - a.st;
  if (c % g) return false;
  c /= g;
  long long mod = a.d / g * b.d;
  long long tp = mul(a.d, x, mod);
  tp = mul(tp, c, mod);
  tp = (tp + a.st) % mod;
  long long rem = tp;
  a.st = rem;
  a.d = mod;
  return true;
}
int main() {
  n = read();
  for (int i = 1; i <= n; ++i) {
    int a = read();
    int b = read();
    dvd(a);
    dvd(b);
    in[i][0] = a;
    in[i][1] = b;
  }
  sort(d + 1, d + 1 + dcnt);
  dcnt = unique(d + 1, d + 1 + dcnt) - d - 1;
  for (int i = 1; i <= n; ++i) {
    long long x = in[i][0], y = in[i][1];
    for (int j = 1; j <= dcnt; ++j) {
      while (x % d[j] == 0) {
        a[i][j].st++;
        x /= d[j];
      }
      while (y % d[j] == 0) {
        a[i][j].d++;
        y /= d[j];
      }
    }
  }
  if (n == 1) {
    makeans(1, 0);
    judge();
  }
  int rem = dcnt;
  for (int j = 1; j <= dcnt; ++j) {
    int k = -1;
    int pos = -1;
    for (int i = 1; i <= n; ++i) {
      if (a[i][j].d == 0) {
        if (k == -1) {
          k = a[i][j].st;
        } else {
          if (a[i][j].st != k) WA();
        }
      } else
        pos = i;
    }
    if (k == -1) continue;
    if (pos == -1) {
      vis[j] = 1;
      --rem;
      continue;
    }
    if (k < a[pos][j].st) {
      WA();
    }
    k -= a[pos][j].st;
    if (k % a[pos][j].d) WA();
    k /= a[pos][j].d;
    makeans(pos, k);
    judge();
  }
  if (rem == 0) {
    makeans(1, 0);
    judge();
  }
  if (rem > 1) {
    int pos = 0;
    for (int j = 1; j <= dcnt; ++j)
      if (!vis[j]) {
        pos = j;
        break;
      }
    for (int j = pos + 1; j <= dcnt; ++j) {
      if (vis[j]) continue;
      for (int i = 2; i <= n; ++i) {
        x[0][0] = a[1][pos].d;
        x[0][1] = -a[i][pos].d;
        x[0][2] = a[i][pos].st - a[1][pos].st;
        x[1][0] = a[1][j].d;
        x[1][1] = -a[i][j].d;
        x[1][2] = a[i][j].st - a[1][j].st;
        int tp = xiao();
        if (tp == 1) vis[j] = 1;
        if (tp == -1) WA();
        if (tp == 0) {
          makeans(1, x[0][2]);
          judge();
        }
      }
    }
  }
  int pos = 0;
  for (int j = 1; j <= dcnt; ++j)
    if (!vis[j]) {
      pos = j;
      break;
    }
  eq now;
  now.st = 0;
  now.d = 1;
  for (int i = 1; i <= n; ++i) {
    if (!bind(now, a[i][pos])) WA();
  }
  for (int i = 1; i <= n; ++i) {
    while (now.st < a[i][pos].st) {
      now.st += now.d;
    }
  }
  long long x = (now.st - a[1][pos].st) / a[1][pos].d;
  makeans(1, x);
  judge();
  close();
  return 0;
}
