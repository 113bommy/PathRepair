#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 19;
const int P = (119 << 23) + 1;
const int G = 3;
const int NUM = 20;
long long wn[NUM];
long long A[N], B[N];
long long Pow(long long a, long long b, long long mo) {
  long long ans = 1;
  a %= mo;
  for (; b; b >>= 1, a = a * a % mo)
    if (b & 1) ans = ans * a % mo;
  return ans;
}
void fly(long long a[], int len) {
  for (int i = 0, j = 0; i < len; i++) {
    if (i > j) swap(a[i], a[j]);
    for (int k = len >> 1; (j ^= k) < k; k >>= 1)
      ;
  }
}
void NTT(long long a[], int len, int op) {
  fly(a, len);
  for (int id = 1; (1 << id) <= len; id++) {
    for (int j = 0; j < len; j += (1 << id)) {
      long long w = 1;
      for (int k = j; k < j + (1 << id) / 2; k++) {
        long long A0 = a[k] % P;
        long long A1w = w * a[k + (1 << id) / 2] % P;
        a[k] = (A0 + A1w) % P;
        a[k + (1 << id) / 2] = (A0 - A1w + P) % P;
        w = w * wn[id] % P;
      }
    }
  }
  if (op == -1) {
    for (int i = 1; i <= len / 2 - 1; i++) swap(a[i], a[len - i]);
    long long inv = Pow(len, P - 2, P);
    for (int i = 0; i <= len - 1; i++) a[i] = a[i] * inv % P;
  }
}
vector<long long> vec[300500];
long long fac[100500], inv[100500];
long long C(int n, int m) { return fac[n] * inv[m] % P * inv[n - m] % P; }
void mul(vector<long long> &a, vector<long long> &b, vector<long long> &c) {
  int n = max(a.size(), b.size()), nn = 1;
  while (nn < 2 * n) nn *= 2;
  for (int i = 0; i <= nn; i++) A[i] = B[i] = 0;
  for (int i = 0; i <= (int)a.size() - 1; i++) A[i] = a[i];
  for (int i = 0; i <= (int)b.size() - 1; i++) B[i] = b[i];
  NTT(A, nn, 1);
  NTT(B, nn, 1);
  for (int i = 0; i < nn; i++) A[i] = A[i] * B[i] % P;
  NTT(A, nn, -1);
  c.resize(nn);
  for (int i = 0; i <= nn - 1; i++) c[i] = A[i];
}
long long solve(int n, int a, int b) {
  int nn = 1;
  while (nn < n) nn *= 2;
  for (int i = 0; i <= n - 1; i++) vec[i].push_back(i), vec[i].push_back(1);
  for (int i = n; i <= nn - 1; i++) vec[i].push_back(1);
  for (int i = nn; i > 1; i >>= 1) {
    int del = i >> 1;
    for (int j = 0; j <= del - 1; j++) {
      mul(vec[j], vec[j + del], vec[j]);
    }
  }
  return vec[0][a + b - 2];
}
int main() {
  for (int i = 0; i <= NUM - 1; i++) wn[i] = Pow(G, (P - 1) / (1 << i), P);
  fac[0] = 1;
  for (int i = 1; i <= 100000; i++) fac[i] = fac[i - 1] * i % P;
  inv[100000] = Pow(fac[100000], P - 2, P);
  for (int i = 100000; i >= 1; i--) inv[i - 1] = inv[i] * i % P;
  int n, a, b;
  scanf("%d%d%d", &n, &a, &b);
  if (a + b - 2 > n - 1)
    puts("0");
  else {
    long long ans = C(a + b - 2, a - 1);
    ans *= solve(n - 1, a, b);
    printf("%lld\n", ans % P);
  }
  return 0;
}
