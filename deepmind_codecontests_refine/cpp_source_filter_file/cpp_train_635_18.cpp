#include <bits/stdc++.h>
using namespace std;
const int N = 100000, M = 10, pw[5] = {1, 10, 100, 1000, 10000};
const unsigned long long mod = 1ULL << 58, inv = 6723469279985657373ULL;
const unsigned long long cir[5] = {1, -1ULL, 1, -1ULL, 1};
struct comp {
  unsigned long long a[M];
  comp(int X = 0) {
    a[0] = X;
    for (int i = 1; i < M; ++i) a[i] = 0;
  }
  unsigned long long &operator[](const int &p) { return a[p]; }
  comp operator+(const comp &p) const {
    comp res;
    for (int i = 0; i < M; ++i) res.a[i] = a[i] + p.a[i];
    return res;
  }
  comp operator-(const comp &p) const {
    comp res;
    for (int i = 0; i < M; ++i) res.a[i] = a[i] - p.a[i];
    return res;
  }
  comp operator*(const unsigned long long &p) const {
    comp res;
    for (int i = 0; i < M; ++i) res.a[i] = a[i] * p;
    return res;
  }
  comp operator*(const comp &p) const {
    comp res;
    for (int i = 0; i < M; ++i)
      for (int j = 0; j < M; ++j) res.a[(i + j) % M] += a[i] * p.a[j];
    return res;
  }
};
comp Power(comp a, int k) {
  comp res(1);
  for (; k; k >>= 1, a = a * a)
    if (k & 1) res = res * a;
  return res;
}
comp wn[M + 9];
void Get_wn() {
  wn[0][0] = wn[M][0] = 1;
  wn[1][1] = 1;
  for (int i = 1; i < M; ++i) wn[i] = wn[i - 1] * wn[1];
}
int gg = 0;
void DWT(comp *a, int t) {
  static comp dft[M];
  for (int d = 0; d < 5; ++d) {
    for (int i = 0; i < N; ++i) {
      if (i / pw[d] % M) continue;
      for (int j = 0; j < M; ++j) dft[j] = 0;
      for (int j = 0; j < M; ++j)
        for (int k = 0; k < M; ++k)
          dft[j] =
              dft[j] + a[i + k * pw[d]] * wn[t ? M - j * k % M : j * k % M];
      for (int j = 0; j < M; ++j) a[i + j * pw[d]] = dft[j];
    }
  }
  if (!t) return;
  for (int i = 0; i < N; ++i) a[i] = a[i] * inv;
}
int n;
comp a[N + 9];
void into() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    ++a[x][0];
  }
}
void Get_ans() {
  DWT(a, 0);
  for (int i = 0; i < N; ++i) a[i] = Power(a[i], n);
  DWT(a, 1);
}
void work() {
  Get_wn();
  Get_ans();
}
void Print(comp a) {
  for (int i = M - 5; i >= 0; --i)
    for (int j = 0; j < 5; ++j) a[i + j] -= a[i + 4] * cir[j];
  printf("%d\n", a[0] >> 5 & mod - 1);
}
void outo() {
  for (int i = 0; i < n; ++i) Print(a[i]);
}
int main() {
  into();
  work();
  outo();
  return 0;
}
