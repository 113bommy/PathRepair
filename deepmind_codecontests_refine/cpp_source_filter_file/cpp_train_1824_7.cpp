#include <bits/stdc++.h>
using namespace std;
const int NN = 1000000 + 117;
const int MM = 100000 + 117;
const int mod = 1e9 + 7;
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
int m, n;
struct VEC {
  long long x, y;
  VEC(long long a_ = 0, long long b_ = 0) { x = a_, y = b_; }
  VEC operator+(VEC a) { return VEC(x + a.x, y + a.y); }
  VEC operator-(VEC a) { return VEC(x - a.x, y - a.y); }
  long long operator*(VEC a) { return x * a.y - y * a.x; }
  void mo() { x %= mod, y %= mod; }
} a[NN];
long long mk[2 * NN][2] = {};
VEC mk2[2 * NN] = {};
VEC mul(long long k, VEC a) {
  a.x = a.x * k % mod;
  a.y = a.y * k % mod;
  return a;
}
void mark(int l, int r, long long k, long long stb) {
  long long b = stb - k * l;
  (mk[l][0] += b) %= mod;
  (mk[l][1] += k) %= mod;
  (mk[r + 1][0] -= b) %= mod;
  (mk[r + 1][1] -= k) %= mod;
}
void mark2(int l, int r, VEC ad) {
  mk2[l] = mk2[l] + ad;
  mk2[r + 1] = mk2[r + 1] - ad;
  mk2[l].mo();
  mk2[r + 1].mo();
}
long long tri(VEC a, VEC b, VEC c) { return (b - a) * (c - b); }
long long getres() {
  for (int i = 1; i <= 2 * n; ++i) {
    (mk[i][0] += mk[i - 1][0]) %= mod;
    (mk[i][1] += mk[i - 1][1]) %= mod;
    mk2[i] = mk2[i] + mk2[i - 1];
    mk2[i].mo();
  }
  long long res = 0;
  for (int i = 1; i <= 2 * n; ++i) {
    long long c = (mk[i][1] * i + mk[i][0]) % mod;
    res = (res + (a[i] * a[i + 1]) % mod * c) % mod;
    res = (res + (mk2[i] * a[i])) % mod;
  }
  return res;
}
int main() {
  n = read();
  long long sum = 0;
  long long res = 0;
  for (int i = n; i >= 1; --i) {
    a[i].x = read();
    a[i].y = read();
  }
  for (int i = n + 1; i <= 2 * n; ++i) a[i] = a[i - n];
  a[2 * n + 1] = a[2 * n];
  for (int i = 1; i <= n; ++i) {
    sum += a[i] * a[i + 1];
  }
  int pos = 1;
  long long nows = 0;
  a[0] = a[n];
  res = ((long long)n * (n - 3) / 2) % mod * (sum % mod) % mod;
  for (int i = 1; i <= n; ++i) {
    nows -= tri(a[pos], a[i - 1], a[i]);
    while (nows * 2 < sum) {
      nows += tri(a[i], a[pos], a[pos + 1]);
      ++pos;
    }
    int xt = pos - 1;
    int cha = xt - i;
    mark(i, xt - 1, -1, cha);
    mark2(i, xt, mul(-1, a[i]));
    mark(xt + 1, i + n - 1, 1, 1);
    mark2(xt + 1, i + n - 1, mul(1, a[i]));
  }
  res -= getres();
  res %= mod;
  res = (res + mod) % mod;
  printf("%lld\n", res);
  close();
  return 0;
}
