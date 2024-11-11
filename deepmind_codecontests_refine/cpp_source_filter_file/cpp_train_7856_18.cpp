#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
long double PI = acos(-1);
struct base {
  long double a, b;
  base(long double _a = 0.0, long double _b = 0.0) : a(_a), b(_b) {}
  const base operator+(const base &c) const { return base(a + c.a, b + c.b); }
  const base operator-(const base &c) const { return base(a - c.a, b - c.b); }
  const base operator*(const base &c) const {
    return base(a * c.a - b * c.b, a * c.b + b * c.a);
  }
};
const int N = 1 << 19;
base w_pre[N | 1], w[N | 1];
int rev[N];
void calcw() {
  for (int i = 0; i <= N; ++i)
    w_pre[i] = base(cos(2 * PI / N * i), sin(2 * PI / N * i));
}
void calcrev(int n) {
  int sz = 31 - __builtin_clz(n);
  sz = abs(sz);
  for (int i = 1; i < n - 1; ++i)
    rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << sz - 1);
}
void fft(base *p, int n, int dir = 0) {
  for (int i = 1; i < n - 1; i++)
    if (i < rev[i]) swap(p[i], p[rev[i]]);
  for (int h = 1; h < n; h <<= 1) {
    int l = h << 1;
    if (!dir)
      for (int j = 0; j < h; ++j) w[j] = w_pre[N / l * j];
    else
      for (int j = 0; j < h; ++j) w[j] = w_pre[N - N / l * j];
    for (int j = 0; j < n; j += l) {
      base t, *wn = w;
      base *u = p + j, *v = u + h, *e = v;
      while (u != e) {
        t = *v * *wn;
        *v = *u - t;
        *u = *u + t;
        ++u, ++v, ++wn;
      }
    }
  }
  if (dir)
    for (int i = 0; i < n; ++i) p[i].a /= n, p[i].b /= n;
}
const int M = 2e5 + 10;
char S[M], T[M];
int n, m, k, tot[M], sz = 1, cnt, p[M];
base A[N], B[N];
void contribute(char c) {
  for (int i = 0; i < n; i++) {
    if (S[i] == c) {
      ++p[max(i - k, 0)];
      --p[min(i + k + 1, n)];
    }
  }
  for (int i = 1; i < n; i++) p[i] += p[i - 1];
  for (int i = 0; i < n; i++) A[i] = base(p[i] > 0, 0), p[i] = 0;
  for (int i = n; i < sz; i++) A[i] = base(0, 0);
  for (int i = 0; i < m; i++) B[i] = base(T[m - i - 1] == c, 0);
  for (int i = m; i < sz; i++) B[i] = base(0, 0);
  fft(A, sz);
  fft(B, sz);
  for (int i = 0; i < sz; i++) A[i] = A[i] * B[i];
  fft(A, sz, 1);
  for (int i = m; i < n; i++) tot[i] += A[i].a + 0.5;
}
int main(int argc, char const *argv[]) {
  scanf("%d %d %d", &n, &m, &k);
  scanf("%s", S);
  scanf("%s", T);
  int t = n + m - 1;
  while (sz < t) sz <<= 1;
  calcw();
  calcrev(sz);
  contribute('A');
  contribute('T');
  contribute('G');
  contribute('C');
  for (int i = m; i < n; i++)
    if (tot[i] == m) ++cnt;
  printf("%d\n", cnt);
}
