#include <bits/stdc++.h>
using namespace std;
typedef double db[1200010];
typedef int arr32[300010];
arr32 x, g;
db sz, ur, val1, val2;
double p, q, ura;
int n;
void update(int k, int l, int r) {
  sz[k] = sz[(k << 1)] * sz[(k << 1) + 1];
  val1[k] = val1[(k << 1)] * sz[(k << 1) + 1] + val1[(k << 1) + 1];
  val2[k] = val2[(k << 1) + 1] * sz[(k << 1)] + val2[(k << 1)];
  ur[k] = ur[(k << 1)] + ur[(k << 1) + 1] * sz[(k << 1)];
}
void inser(int k, int l, int r, int x) {
  if (l == r) {
    sz[k] = ur[k] = val1[k] = val2[k] = 0.5;
    return;
  }
  if (x <= ((l + r) >> 1))
    inser((k << 1), l, ((l + r) >> 1), x);
  else
    inser((k << 1) + 1, ((l + r) >> 1) + 1, r, x);
  update(k, l, r);
}
void findL(int k, int l, int r, int x) {
  if (l > x) return;
  if (r <= x) {
    p *= sz[k];
    p += val1[k];
    ura *= sz[k], ura += ur[k];
    return;
  }
  findL((k << 1), l, ((l + r) >> 1), x),
      findL((k << 1) + 1, ((l + r) >> 1) + 1, r, x);
}
void findR(int k, int l, int r, int x) {
  if (r < x) return;
  if (l >= x) {
    q *= sz[k];
    q += val2[k];
    ura *= sz[k], ura += ur[k];
    return;
  }
  findR((k << 1) + 1, ((l + r) >> 1) + 1, r, x),
      findR((k << 1), l, ((l + r) >> 1), x);
}
void build(int k, int l, int r) {
  if (l == r) {
    sz[k] = ur[k] = val1[k] = val2[k] = 1;
    return;
  }
  build((k << 1), l, ((l + r) >> 1)),
      build((k << 1) + 1, ((l + r) >> 1) + 1, r);
  update(k, l, r);
}
bool cmp(const int &a, const int &b) { return x[a] > x[b]; }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", x + i), g[i] = i;
  build(1, 1, n);
  double result = 0;
  sort(g + 1, g + n + 1, cmp);
  for (int i = 1; i <= n; ++i) {
    int z = g[i];
    p = 0, ura = 1, findL(1, 1, n, z);
    q = 0, ura = 1, findR(1, 1, n, z);
    result += p * q * x[z] / n / 2;
    inser(1, 1, n, z);
  }
  printf("%.10lf", result / n);
}
