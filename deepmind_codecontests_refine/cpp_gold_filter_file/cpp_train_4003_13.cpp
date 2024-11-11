#include <bits/stdc++.h>
using namespace std;
const int N = (1 << 20) + 5;
const int P = 998244353;
const int G = 3;
const int NUM = 20;
long long wn[NUM];
long long quick_mod(long long a, long long b, long long mod) {
  long long tmp = 1;
  while (b) {
    if (b & 1) tmp = tmp * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return tmp;
}
void GetWn() {
  for (int i = 0; i < NUM; i++) {
    int t = 1 << i;
    wn[i] = quick_mod(G, (P - 1) / t, P);
  }
}
void Rader(long long a[], int len) {
  int j = len >> 1;
  for (int i = 1; i < len - 1; i++) {
    if (i < j) swap(a[i], a[j]);
    int k = len >> 1;
    while (j >= k) {
      j -= k;
      k >>= 1;
    }
    if (j < k) j += k;
  }
}
void NTT(long long a[], int len, int dft) {
  Rader(a, len);
  int id = 0;
  for (int h = 2; h <= len; h <<= 1) {
    id++;
    for (int j = 0; j < len; j += h) {
      long long w = 1;
      for (int k = j; k < j + h / 2; k++) {
        long long u = a[k] % P;
        long long t = w * a[k + h / 2] % P;
        a[k] = (u + t) % P;
        a[k + h / 2] = (u - t + P) % P;
        w = w * wn[id] % P;
      }
    }
  }
  if (dft == -1) {
    for (int i = 1; i < len / 2; i++) swap(a[i], a[len - i]);
    long long inv = quick_mod(len, P - 2, P);
    for (int i = 0; i < len; i++) a[i] = a[i] * inv % P;
  }
}
long long p[N];
long long tmp[N];
long long inv[N];
long long inv2 = quick_mod(2, P - 2, P);
void Get_Inv(long long a[], long long b[], int n) {
  if (n == 1) {
    b[0] = quick_mod(a[0], P - 2, P);
    return;
  }
  Get_Inv(a, b, n >> 1);
  for (int i = 0; i < n; i++) tmp[i] = a[i];
  for (int i = n; i < 2 * n; i++) tmp[i] = 0;
  NTT(tmp, n << 1, 1);
  NTT(b, n << 1, 1);
  for (int i = 0; i < n << 1; i++)
    b[i] = 1LL * b[i] * (2 - 1LL * b[i] * tmp[i] % P) % P;
  NTT(b, n << 1, -1);
  for (int i = 0; i < n; i++) b[i] = (b[i] + P) % P;
  for (int i = n; i < 2 * n; i++) b[i] = 0;
}
long long h[N];
void Get_Sqrt(long long a[], long long b[], int n) {
  if (n == 1) {
    b[0] = 1;
    b[1] = 0;
    return;
  }
  Get_Sqrt(a, b, n >> 1);
  for (int i = 0; i < (n << 1); i++) inv[i] = 0;
  Get_Inv(b, inv, n);
  for (int i = 0; i < n; i++) h[i] = a[i];
  for (int i = n; i < 2 * n; i++) h[i] = 0;
  NTT(h, n << 1, 1);
  NTT(b, n << 1, 1);
  NTT(inv, n << 1, 1);
  for (int i = 0; i < (n << 1); i++)
    b[i] = (b[i] + h[i] * inv[i] % P) % P * inv2 % P;
  NTT(b, n << 1, -1);
  memset(b + n, 0, sizeof(b[0]) * n);
}
long long c[N], b[N], a[N];
long long pp[N];
int main() {
  GetWn();
  int n, m;
  pp[0] = 1, pp[1] = P - 4;
  NTT(pp, 4, 1);
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) c[i] = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    c[x] = 1;
  }
  for (int i = 1; i <= m; i++) c[i] = (P - 4LL * c[i]) % P;
  c[0] = 1;
  int len = 0;
  while ((1 << len) <= m) len++;
  len = 1 << len;
  Get_Sqrt(c, b, len);
  b[0] = (b[0] + 1) % P;
  Get_Inv(b, a, len);
  for (int i = 1; i <= m; i++) printf("%d\n", 2 * a[i] % P);
  return 0;
}
