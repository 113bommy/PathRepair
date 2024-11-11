#include <bits/stdc++.h>
using namespace std;
template <class T>
void _R(T &x) {
  cin >> x;
}
void _R(int &x) { scanf("%d", &x); }
void _R(int64_t &x) { scanf("%lld", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template <class T, class... U>
void R(T &head, U &...tail) {
  _R(head);
  R(tail...);
}
template <class T>
void _W(const T &x) {
  cout << x;
}
void _W(const int &x) { printf("%d", x); }
void _W(const int64_t &x) { printf("%lld", x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template <class T, class U>
void _W(const pair<T, U> &x) {
  _W(x.first);
  putchar(' ');
  _W(x.second);
}
template <class T>
void _W(const vector<T> &x) {
  for (auto i = x.begin(); i != x.end(); _W(*i++))
    if (i != x.cbegin()) putchar(' ');
}
void W() {}
template <class T, class... U>
void W(const T &head, const U &...tail) {
  _W(head);
  putchar(sizeof...(tail) ? ' ' : '\n');
  W(tail...);
}
int MOD = 1e9 + 7;
void ADD(int &x, long long v) {
  x = (x + v) % MOD;
  if (x < 0) x += MOD;
}
const int SIZE = 111;
long long mypow(long long x, long long y) {
  x %= MOD;
  long long res = 1 % MOD;
  while (y) {
    if (y & 1) res = res * x % MOD;
    y >>= 1;
    x = x * x % MOD;
  }
  return res;
}
int r;
int a[4];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int p[SIZE][SIZE], pid;
int sqr(int x) { return x * x; }
bool Out(int x, int y) { return sqr(x) + sqr(y) > sqr(r); }
int d[7847][7847];
int main() {
  R(r);
  int sum_a = 0;
  for (int i = 0; i < (4); ++i) {
    R(a[i]);
    sum_a += a[i];
  }
  for (int i = 0; i < (4); ++i) {
    a[i] = a[i] * mypow(sum_a, MOD - 2) % MOD;
  }
  int O_O = -1;
  for (int x = (-r); x <= (r); ++x)
    for (int y = (-r); y <= (r); ++y) {
      if (!Out(x, y)) {
        if (!x && !y) O_O = pid;
        p[(x) + 55][(y) + 55] = pid++;
      }
    }
  for (int x = (-r); x <= (r); ++x)
    for (int y = (-r); y <= (r); ++y) {
      if (Out(x, y)) continue;
      d[p[(x) + 55][(y) + 55]][pid] = 1;
      d[p[(x) + 55][(y) + 55]][p[(x) + 55][(y) + 55]] = 1;
      for (int i = 0; i < (4); ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (!Out(nx, ny)) {
          ADD(d[p[(x) + 55][(y) + 55]][p[(nx) + 55][(ny) + 55]], -a[i]);
        }
      }
    }
  int rid = 0;
  for (int i = 0; i < (pid); ++i) {
    {
      int tt;
      for (tt = rid; !d[tt][i]; tt++)
        ;
      if (tt != rid) {
        for (int k = (i); k <= (pid); ++k) swap(d[tt][k], d[rid][k]);
      }
    }
    int inv = mypow(d[rid][i], MOD - 2);
    for (int j = rid + 1; j < rid + 110 && j < pid; j++) {
      if (d[j][i]) {
        int mul = (long long)d[j][i] * inv % MOD;
        for (int k = (i + 1); k < (min(i + 110, pid)); ++k) {
          ADD(d[j][k], -(long long)d[rid][k] * mul);
        }
        ADD(d[j][pid], -(long long)d[rid][pid] * mul);
        d[j][i] = 0;
      }
    }
    rid++;
  }
  for (int i = pid - 1; i > O_O; i--) {
    int mul = mypow(d[i][i], MOD - 2) * d[i][pid] % MOD;
    for (int j = i - 1; j >= O_O; j--) {
      if (d[j][i]) {
        ADD(d[j][pid], -(long long)d[j][i] * mul);
      }
    }
  }
  W(d[O_O][pid] * mypow(d[O_O][O_O], MOD - 2) % MOD);
  return 0;
}
